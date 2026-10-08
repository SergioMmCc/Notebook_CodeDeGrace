# Es importante tener en cuenta que python es aproximadamente 40 veces mas lento que C++

def main ():
    # Leer una linea completa, separar los elementos por los espacios y almacenarlos en una 
    # lista (permitiendo repetidos)
    read = input()
    numbers = read.split()
    numbers = list(map(int, numbers)) # 'map' transforma cada elemento de numbers en un int

    #Leer un entero
    n = int(input())

    # Leer un número flotante
    d = float(input())

    # Leer una cadena
    s = input()

    # Leer hasta fin de archivo
    def func():
        while(True):
            try:
                n = int(input()) # Cambiar por input() si no me dan solo un numero
                # Procesar lo que sea necesario
            except EOFError:
                break



    # Lectura y escritura rapida
    import sys
    input = sys.stdin.readline # Reemplaza input() por una version mucho mas rapida (poner afuera de todas las funciones)
    # readline NO quita el '\n' del final. int() y float() lo ignoran, pero con cadenas hay que limpiarlo
    n = int(input())
    numbers = list(map(int, input().split()))
    s = input().strip() # strip() quita espacios y el salto de linea
 
    # Con readline, al llegar a fin de archivo devuelve '' (NO lanza EOFError)
    # Leer hasta fin de archivo:
    for line in sys.stdin:
        pass # Procesar line
 
    # Leer TODA la entrada de una vez y separarla por espacios y saltos de linea
    data = sys.stdin.read().split()
    n = int(data[0]) # n es un token
    numbers = list(map(int, data[1:n + 1])) # lista con los n tokens siguientes [1, n+1)
 
    
    # Escribir: muchos print() son lentos. Acumular y escribir una sola vez
    out = []
    out.append(str(n)) # Cada elemento es una linea de salida
    sys.stdout.write("\n".join(out) + "\n") # Imprime todo, cada elemento en una linea diferente
 
    print(*numbers) # Imprime los elementos separados por espacio
    print("\n".join(map(str, numbers))) # Un elemento por linea


    # Tamaño de una cadena
    x = len(s)

    # Agregar un caracter a una cadena
    # Las cadenas son inmutables asi que al agregarle un caracter se crea una cadena nueva, lo cual es costoso
    # Es mejor manejarlas con listas de char

    # Negar un bool
    cond = True
    not cond # Esto seria False

    # Potencia de un numero
    ans = base ** exp
    ans = pow(base, exp, mod) # Exponenciacion binaria
    inv = pow(num, -1, mod) # Calcula el inverso modular de num, siempre que num y mod sean coprimos (Desde Python 3.8)

    # Ciclo for
    for i in range (0, 5): # Esto iria hasta el 4
    for auto in autos: # autos seria una lista

    # Condicionales
    if(cond1):
    elif(cond2):
    else:

    # Minimo y maximo
    mina = min(mina, number)
    maxa = max(maxa, number)

    # Para usar decimales precisos
    from decimal import Decimal, getcontext
 
    getcontext().prec = 70 # Cantidad de digitos decimales a usar
    ans = Decimal("0.0") # Inicializar un numero decimal
    val += Decimal("1") # Para constantes usar Decimal tambien
    val += Decimal("1") / r # Se puede dividir por un entero sin problema
    print(f"{ans:.6f}") # Imprimir con 6 decimales


    # Convertir un numero base x (guardado como cadena) en un entero base 10
    n10 = int(n2, x)

    # Pasar un numero de base 10 a base 2 (se convierte a cadena) (falla con negativos)
    ans2 = bin(ans10)[2:] # Para cambiar de base 10 a cualquier otra base (que no sea base 2) toca a mano

    # Evaluar una string que es una expresion matematica (tambien puede tener parentesis)
    result = eval(expresion) # Toma ^ como XOR, ** como potencia, / da float, // es division parte entera

    # Metodos de listas (list)
    # Resaltar que una sola lista puede contener varios tipos de datos, incluida otra lista
    lista = [1, "dos", [3, "cuatro"], 5.0, True] # Declarar
    exp = [val] * n # Crear una lista de n elementos iguales a val
    n = lista[i] # Sirve para acceder al elemento i de una lista
    lista.append(6) # Agregar un elemento
    lista.remove("dos") # Eliminar la primera aparicion de "dos", ValueError si no esta
    lista.sort() # Ordenar (todos los elementos tienen que ser comparables entre si (ej: int con str falla), sino da TypeError)
    print(lista) # Imprimir toda la lista
    lista.extend([7, 8])  # Agrega 7 y 8 a la lista
    lista.insert(1, 'a') # Inserto 'a' en la posicion 1, el resto de elementos corren un espacio a la derecha
    n = lista.pop() # Elimina el ultimo elemento de la lista y se lo asigna a 'n'
    n = lista.pop(3) # Elimina el elemento en la posicion 3 de la lista y se lo asigna a 'n'
    lista.clear() # Elimina todos los elementos de la lista, quedando: lista = []
    lista.reverse() # Invierte los elementos de la lista
    indice = lista.index("dos") # Devuelve el indice de la primera aparicion de "dos" (lanza ValueError si no esta)
    indice2 = lista.index(x, start) # Comienza a buscar desde el indice start
    indice3 = lista.index(x, start, end) # Devuelve la primera aparicion de x en el rango [start, end)
    conteo = lista.count(x) # Devuelve el numero de veces que aparece 'x' en la lista


    # Metodos deque 
    from collections import deque
    # list.pop(0) y list.insert(0, x) son O(n). Para colas (BFS) usar deque
    d = deque() # Declarar vacio
    d = deque([1, 2, 3]) # Declarar desde una lista
    d.append(4) # Agrega a la derecha: [1, 2, 3, 4]
    d.appendleft(0) # Agrega a la izquierda: [0, 1, 2, 3, 4]
    x = d.pop() # Elimina y retorna el de la derecha
    x = d.popleft() # Elimina y retorna el de la izquierda
    # pop() y popleft() lanzan IndexError si el deque esta vacio
    x = d[0] # Primer elemento (O(1))
    x = d[-1] # Ultimo elemento (O(1)). Acceder a posiciones del medio es O(n)
    d.extend([5, 6]) # Agrega varios a la derecha
    d.extendleft([-1, -2]) # Agrega a la izquierda uno por uno, asi que queda en orden inverso: [-2, -1, ...]
    d.rotate(1) # Rota 1 posicion a la derecha. Con -1 rota a la izquierda
    d.reverse() # Invierte el deque
    d.remove(5) # Elimina la primera aparicion (ValueError si no esta)
    n = d.count(5) # Cuenta cuantas veces aparece
    n = len(d) # Tamaño
    d.clear() # Vacia el deque
    if d: # Un deque vacio es False, uno con elementos es True
        pass
    d = deque(maxlen=3) # Con maxlen, al agregar de mas se elimina del extremo opuesto


    # heapq (cola de prioridad). Es un min-heap implementado sobre una lista normal
    import heapq
    h = [] # Declarar vacio
    heapq.heappush(h, 5) # Agregar un elemento. O(log n)
    heapq.heappush(h, 2)
    x = heapq.heappop(h) # Elimina y retorna el MENOR. O(log n). IndexError si esta vacio
    x = h[0] # Ver el menor sin eliminarlo. O(1)
    heapq.heapify(lista) # Convierte una lista en heap, en el mismo lugar. O(n)
    x = heapq.heappushpop(h, 3) # Agrega 3 y luego elimina y retorna el menor (puede ser el mismo 3) (mas eficiente que por separado)
    x = heapq.heapreplace(h, 3) # Elimina y retorna el menor y luego agrega 3
    mayores = heapq.nlargest(3, lista) # Los 3 mayores, de mayor a menor
    menores = heapq.nsmallest(3, lista) # Los 3 menores, de menor a mayor
    # Imprimir la lista del heap NO la muestra ordenada, solo se garantiza que h[0] es el menor
    # Con tuplas se compara el primer elemento y, si empatan, el segundo, y asi
    heapq.heappush(h, (dist, nodo)) # Prioridad por distancia
    dist, nodo = heapq.heappop(h)


    # Metodos de sets
    # No tiene elementos repetidos, no esta ordenado
    s = {1, 2, 3} # Declarar
    s.add(4) # Agregar un elemento
    s.remove(4) # Eliminar un elemento. Si el elemento no esta lanza un error
    s.discard(4) # Tambien elimina un elemento pero si no esta no genera error
    x = s.pop() # Elimina y retorna un elemento arbitrario
    s.clear() # Vacía el conjunto
    s1 = {1, 2}
    s2 = {2, 3}
    s3 = {4, 5, 6}

    # Metodos de operaciones de conjuntos
    # Union de conjuntos
    s4 = s1.union(s2, s3)
    s4 = s1 | s2 | s3

    # Interseccion de conjuntos
    s4 = s1.intersection(s2, s3)
    s4 = s1 & s2 & s3

    # Retorna lo que esta en el primer conjunto pero no en los demas
    s4 = s1.difference(s2, s3)
    s4 = s1 - s2 - s3

    # Elementos que estan en un numero impar de conjuntos
    s4 = s1.symmetric_difference(s2).symmetric_difference(s3)
    s4 = (s1 ^ s2) ^ s3

    
    # Metodos para relaciones de conjuntos

    s1.issubset(s2) # Devuelve True si s1 es subconjunto de s2
    s1.issuperset(s2) # Devuelve True si s1 es superconjunto de s2
    s1.isdisjoint(s2) # Devuelve True si no tienen elementos en comun


    # Metodos de actualizacion

    # Actualiza s1 con la union entre s1 y s2
    s1.update(s2) 
    s1 |= s2

    # Actualiza s1 con la interseccion entre s1 y s2
    s1.intersection_update(s2)
    s1 &= s2

    # Actualiza s1 eliminando los elementos que estan en s2
    s1.difference_update(s2)
    s1 -= s2

    # Actualiza s1 con la diferencia simetrica entre s1 y s2
    s1.symmetric_difference_update(s2)
    s1 ^= s2

    
    # Diccionarios
    dic = {'a' : 1, 'b' : 2} # Declarar
    n = dic.get('a') # Acceder al value de la key 'a', sino esta devuelve None
    n = dic.get('a', 0) # Si la key 'a' esta, devuelve su value, sino devuelve 0
    claves = list(dic.keys()) # Retorna una lista con todas las keys
    valores = list(dic.values()) # Retorna una lista con todos los values
    parejas = list(dic.items()) # Retorna una lista de tuplas con todos los pares key-value
    dic.update({'c' : 3, 'd' : 4}) # Insertar elementos en dic
    dic.update(dic2) # Actualizar dic con los elementos de dic2
    a = dic.pop('a') # Elimina y retorna el value cuya key es 'a', sino esta genera error
    a = dic.pop('a', 0) # Elimina y retorna el value cuya key es 'a', sino esta devuelve 0
    a = dic.popitem() # Elimina y devuelve el ultimo par key-value que fue insertado
    dic.clear() # Vacia el diccionario
    valor = dic.setdefault('a') # Si esta esa key, devuelve su value
    valor = dic.setdefault('a', 2) # Si esta esa key, devuelve su valor e ignora el 2
    value = dic.setdefault('e', 5) # Si no esta esa key, la agrega con ese value y retorna el value
    keys = ['a', 'b', 'c']
    dic = dict.fromkeys(keys, 0) # Crea un nuevo diccionario con claves del iterable y todas con el mismo valor


    # bisect (busqueda binaria). La lista DEBE estar ordenada. O(log n)
    from bisect import bisect_left, bisect_right
    a = [1, 2, 4, 4, 4, 7]
    i = bisect_left(a, 4) # 2: primera posicion con elemento >= 4 (retorna len(a) si no hay ninguno)
    i = bisect_right(a, 4) # 5: primera posicion con elemento > 4 (justo despues de la ultima aparicion)
    cantidad = bisect_right(a, 4) - bisect_left(a, 4) # 3: cuantas veces aparece el 4
    i = bisect_left(a, 4, lo, hi) # Buscar solo en el rango [lo, hi)


main()