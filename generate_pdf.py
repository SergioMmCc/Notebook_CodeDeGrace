import subprocess
import os
import re
import shutil
import unicodedata

code_dir = "code"

# Maximo de simbolos repetidos seguidos (ej: /* ********* */). Las tiras mas largas
# se acortan para que no se salgan de la columna.
MAX_RUN = 30
RUN_RE = re.compile(r'([*=\-#_~])\1{%d,}' % MAX_RUN)

# Reemplazos de simbolos no ASCII para el codigo dentro de lstlisting.
# Las letras con tilde (a e i o u n u ...) se resuelven solas quitando el acento.
ASCII_MAP = {
    '⁻¹': '^-1',
    '−': '-', '–': '-', '—': '-',
    '²': '^2', '³': '^3', '¹': '^1', '⁻': '^-',
    '°': 'deg', 'º': 'o', 'ª': 'a',
    '’': "'", '‘': "'", '“': '"', '”': '"',
    '·': '*', '×': 'x', '…': '...',
    '≤': '<=', '≥': '>=', '≠': '!=', '→': '->', '←': '<-',
    '⊆': 'subset', '≡': '==', '∩': '&', '∪': '|',
    'σ': 'sigma', 'α': 'alpha', 'β': 'beta', 'π': 'pi',
    '\u00a0': ' ',   # espacio no separable
}
# Caracteres invisibles que se eliminan
INVISIBLES = {'\u200b', '\u200c', '\u200d', '\u2060', '\ufeff'}


def shorten_runs(line):
    """Acorta tiras largas de un mismo simbolo (****, ====, ----) a MAX_RUN."""
    return RUN_RE.sub(lambda m: m.group(1) * MAX_RUN, line)


def asciify(line, filename, lineno):
    """Convierte una linea a ASCII puro y acorta tiras largas de simbolos.
    Avisa si no sabe convertir un caracter."""
    for k in sorted(ASCII_MAP, key=len, reverse=True):
        if k in line:
            line = line.replace(k, ASCII_MAP[k])
    out = []
    for ch in line:
        if ord(ch) < 128:
            out.append(ch)
        elif ch in INVISIBLES or unicodedata.category(ch) in ('Cf', 'Cc'):
            continue
        else:
            base = ''.join(c for c in unicodedata.normalize('NFKD', ch)
                           if not unicodedata.combining(c))
            if base and all(ord(c) < 128 for c in base):
                out.append(base)
            else:
                print('AVISO: caracter no soportado %r (U+%04X) en %s:%d -> se reemplaza por "?"'
                      % (ch, ord(ch), filename, lineno))
                out.append('?')
    return shorten_runs(''.join(out))


def strip_invisibles(text):
    for bad in INVISIBLES:
        text = text.replace(bad, '')
    return text.replace('\u00a0', ' ')


def get_sections():
    sections = []
    section_name = None
    subsections = []
    with open('contents.txt', 'r', encoding='utf-8') as f:
        for line in f:
            if '#' in line:
                line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0:
                continue
            if line[0] == '[':
                if section_name is not None:
                    sections.append((section_name, subsections))
                section_name = line[1:-1]
                subsections = []
            else:
                if section_name is None:
                    raise ValueError('Subsection given without section: %s' % line)
                tmp = line.split('\t', 1)
                if len(tmp) == 1:
                    raise ValueError('Subsection parse error (falta el TAB): %s' % line)
                filename = tmp[0].strip()
                subsection_name = tmp[1].strip()
                subsections.append((filename, subsection_name))
    # Agregar la ultima seccion
    if section_name is not None and subsections:
        sections.append((section_name, subsections))
    return sections


def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp', 'h']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'


# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s


def filter_code(filename):
    """Lee el archivo de codigo, quita '#include "../template.h"' y la linea vacia siguiente,
    y lo convierte a ASCII para que listings no falle."""
    filepath = os.path.join(code_dir, filename)
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    filtered_lines = []
    skip_next = False
    for lineno, line in enumerate(lines, 1):
        if skip_next:
            # Saltar la linea vacia despues del #include
            if line.strip() == '':
                skip_next = False
                continue
            else:
                skip_next = False

        if '#include "../template.h"' in line or '#include"../template.h"' in line:
            skip_next = True
            continue

        filtered_lines.append(asciify(line, filename, lineno))

    # Quitar lineas vacias al final
    while filtered_lines and filtered_lines[-1].strip() == '':
        filtered_lines.pop()
    # Que la ultima linea no tenga salto de linea (evita linea en blanco en lstinputlisting)
    if filtered_lines and filtered_lines[-1].endswith('\n'):
        filtered_lines[-1] = filtered_lines[-1].rstrip('\n')

    # Nombre temporal seguro para LaTeX: sin espacios, &, [], +, etc.
    temp_filename = 'temp_' + re.sub(r'[^A-Za-z0-9_.]', '-', filename)
    with open(temp_filename, 'w', encoding='utf-8') as f:
        f.writelines(filtered_lines)

    return temp_filename


# Filtro de pandoc para los .md: encabezados en negrita (no entran al indice),
# bloques de codigo con listings y tablas como tabular (longtable no funciona en multicols).
MD_FILTER = r"""
local function style_for(classes)
  local c = (classes[1] or ''):lower()
  if c == 'cpp' or c == 'c++' or c == 'c' then return 'cpp' end
  if c == 'python' or c == 'py' then return 'py' end
  if c == 'java' then return 'java' end
  return 'txt'
end

-- Simbolos unicode en texto normal (fuera de matematicas)
local TEXT = {
  ['−'] = '-',
  ['²'] = '\\ensuremath{^{2}}',
  ['³'] = '\\ensuremath{^{3}}',
  ['¹'] = '\\ensuremath{^{1}}',
  ['⁻'] = '\\ensuremath{^{-}}',
  ['°'] = '\\textdegree{}',
  ['º'] = '\\textordmasculine{}',
  ['·'] = '\\textperiodcentered{}',
  ['⊆'] = '\\ensuremath{\\subseteq}',
  ['≡'] = '\\ensuremath{\\equiv}',
  ['∩'] = '\\ensuremath{\\cap}',
  ['∪'] = '\\ensuremath{\\cup}',
  ['σ'] = '\\ensuremath{\\sigma}',
  ['α'] = '\\ensuremath{\\alpha}',
  ['≤'] = '\\ensuremath{\\leq}',
  ['≥'] = '\\ensuremath{\\geq}',
  ['≠'] = '\\ensuremath{\\neq}',
  ['→'] = '\\ensuremath{\\rightarrow}',
}

function Str(el)
  local t = el.text
  if not t:find('[\128-\255]') then return nil end
  local out = {}
  local buf = ''
  for ch in t:gmatch(utf8.charpattern) do
    local rep = TEXT[ch]
    if rep then
      if buf ~= '' then out[#out + 1] = pandoc.Str(buf); buf = '' end
      out[#out + 1] = pandoc.RawInline('latex', rep)
    else
      buf = buf .. ch
    end
  end
  if buf ~= '' then out[#out + 1] = pandoc.Str(buf) end
  return out
end

function CodeBlock(el)
  return pandoc.RawBlock('latex',
    '\\begin{lstlisting}[style=' .. style_for(el.classes) .. ']\n' .. el.text .. '\n\\end{lstlisting}')
end

function Header(el)
  local pre = '\\par\\medskip\\noindent{\\bfseries '
  if el.level == 1 then pre = '\\par\\medskip\\noindent{\\Large\\bfseries '
  elseif el.level == 2 then pre = '\\par\\medskip\\noindent{\\large\\bfseries ' end
  local inlines = { pandoc.RawInline('latex', pre) }
  for _, i in ipairs(el.content) do table.insert(inlines, i) end
  table.insert(inlines, pandoc.RawInline('latex', '}'))
  return pandoc.Para(inlines)
end

function Math(el)
  local s = el.text
  s = s:gsub('⁻¹', '^{-1}')
  s = s:gsub('·', '\\cdot ')
  s = s:gsub('°', '^{\\circ}')
  s = s:gsub('−', '-')
  s = s:gsub('²', '^{2}')
  s = s:gsub('³', '^{3}')
  s = s:gsub('¹', '^{1}')
  s = s:gsub('⁻', '^{-}')
  s = s:gsub('⊆', '\\subseteq ')
  s = s:gsub('≡', '\\equiv ')
  s = s:gsub('∩', '\\cap ')
  s = s:gsub('∪', '\\cup ')
  s = s:gsub('σ', '\\sigma ')
  s = s:gsub('α', '\\alpha ')
  if el.mathtype == 'DisplayMath' then
    return pandoc.RawInline('latex',
      '\\[\\adjustbox{max width=\\linewidth}{$\\displaystyle ' .. s .. '$}\\]')
  end
  el.text = s
  return el
end

local function cell_tex(cell)
  local s = pandoc.write(pandoc.Pandoc(cell.contents), 'latex')
  s = s:gsub('%s*\n%s*', ' ')
  return (s:gsub('^%s+', ''):gsub('%s+$', ''))
end

local function row_tex(row)
  local cells = {}
  for _, cell in ipairs(row.cells) do cells[#cells + 1] = cell_tex(cell) end
  return table.concat(cells, ' & ') .. ' \\\\'
end

function Table(tbl)
  local cols = {}
  for _, spec in ipairs(tbl.colspecs) do
    local a = tostring(spec[1])
    if a == 'AlignRight' then cols[#cols + 1] = 'r'
    elseif a == 'AlignCenter' then cols[#cols + 1] = 'c'
    else cols[#cols + 1] = 'l' end
  end
  local out = {
    '\\par\\smallskip\\noindent\\adjustbox{max width=\\columnwidth}{%',
    '\\begin{tabular}{|' .. table.concat(cols, '|') .. '|}',
    '\\hline'
  }
  for _, row in ipairs(tbl.head.rows) do
    out[#out + 1] = row_tex(row)
    out[#out + 1] = '\\hline'
  end
  for _, body in ipairs(tbl.bodies) do
    for _, row in ipairs(body.body) do
      out[#out + 1] = row_tex(row)
      out[#out + 1] = '\\hline'
    end
  end
  out[#out + 1] = '\\end{tabular}}\\par\\smallskip'
  return pandoc.RawBlock('latex', table.concat(out, '\n'))
end
"""

MD_FILTER_FILE = 'temp_md_filter.lua'
HAS_PANDOC = shutil.which('pandoc') is not None


def prepare_md(content, filename):
    """Quita invisibles y convierte a ASCII SOLO los bloques de codigo (``` o ~~~)."""
    content = strip_invisibles(content)
    out = []
    in_code = False
    for lineno, line in enumerate(content.splitlines(keepends=True), 1):
        stripped = line.lstrip()
        if stripped.startswith('```') or stripped.startswith('~~~'):
            in_code = not in_code
            out.append(line)
        elif in_code:
            out.append(asciify(line, filename, lineno))
        else:
            out.append(line)
    return ''.join(out)


def md_to_tex(filename):
    """Convierte un .md a un fragmento de LaTeX con pandoc. Devuelve el nombre del .tex temporal."""
    src = os.path.join(code_dir, filename)
    base = re.sub(r'[^A-Za-z0-9_.]', '-', filename)
    stem = os.path.splitext(base)[0]
    temp_tex = 'temp_' + stem + '.tex'

    # Copia limpia del .md para pandoc
    temp_md = 'temp_' + stem + '.md'
    with open(src, 'r', encoding='utf-8', errors='replace') as f:
        content = prepare_md(f.read(), filename)
    with open(temp_md, 'w', encoding='utf-8') as f:
        f.write(content)

    subprocess.run(
        ['pandoc', temp_md,
         '-f', 'gfm+tex_math_dollars',
         '-t', 'latex',
         '--wrap=preserve',
         '--lua-filter=' + MD_FILTER_FILE,
         '-o', temp_tex],
        check=True)
    return temp_tex


def get_tex_section(section_name, subsections):
    """Genera el LaTeX de una seccion"""
    tex = '\\section{%s}\n' % texify(section_name)
    for (filename, subsection_name) in subsections:
        tex += '\\subsection{%s}\n' % texify(subsection_name)
        if filename.lower().endswith('.md') and HAS_PANDOC:
            temp_file = md_to_tex(filename)
            tex += '\\begingroup\\setlength{\\parindent}{0pt}\\setlength{\\parskip}{2pt}\\input{%s}\\par\\endgroup\n' % temp_file
        else:
            temp_file = filter_code(filename)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), temp_file)
        tex += '\\hrulefill\n'
    tex += '\n'
    return tex


def get_tex(sections):
    """Genera el LaTeX de todas las secciones"""
    tex_all = ''

    for (section_name, subsections) in sections:
        # Saltar la seccion Fin porque no tiene contenido
        if section_name == 'Fin':
            continue

        tex_all += get_tex_section(section_name, subsections)

    return tex_all


if __name__ == "__main__":
    if shutil.which('latexmk') is None:
        raise SystemExit('ERROR: latexmk no esta instalado (instala texlive y latexmk).')
    if not HAS_PANDOC:
        print('AVISO: pandoc no esta instalado; los .md se mostraran como texto plano.')
    with open(MD_FILTER_FILE, 'w', encoding='utf-8') as f:
        f.write(MD_FILTER)

    sections = get_sections()
    tex_all = get_tex(sections)

    # Escribir todo el contenido en un solo archivo
    with open('contents.tex', 'w', encoding='utf-8') as f:
        f.write(tex_all)

    # Borrar restos de una compilacion fallida anterior para que no arrastre errores
    subprocess.call(["latexmk", "-C", "notebook.tex"],
                    stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    latexmk_options = ["latexmk", "-pdf", "-interaction=nonstopmode", "notebook.tex"]
    returncode = subprocess.call(latexmk_options)

    remove_files = ["notebook.fls", "notebook.aux", "notebook.fdb_latexmk",
                    "notebook.out", "notebook.toc"]
    if returncode == 0:
        remove_files.append("notebook.log")
    else:
        print('\nERROR: la compilacion fallo. Revisa notebook.log (busca las lineas que empiezan con "!").')
    for file in remove_files:
        if os.path.exists(file):
            os.remove(file)

    # Borrar los archivos temporales (cualquier extension, incluye .md)
    for file in os.listdir('.'):
        if file.startswith('temp_') and os.path.isfile(file):
            os.remove(file)