#include "../template.h"

/*
- Complejidad: add O(1), get_max O(log n).
- Para dp donde las transiciones son en forma de recta:
  dp_i = v_i + max_o_min(dp_j + a_i * m_j), donde:
  * 'j' es un indice menor que 'i'.
  * los valores 'm' representan las pendientes y estan 
    ordenados ascendente o descendentemente.
  * los valores 'a' son el punto donde se evalua la funcion. 
  * 'dp_j' es la interseccion en el eje Y.
  * 'v_i' es un valor que solo depende de 'i'.
  * 'dp_i' es el mejor resultado usando los valores de 'i'.
- Tabla para saber como hacer las queries segun el caso que se busca:
Problema	Pendiente	    Recta	    Respuesta
max	        ascendentes	    (m, b)	    get_max(x)
min	        descendentes	(−m, −b)	-get_max(x)
max	        descendentes	(−m, b)	    get_max(−x)
min	        ascendentes	    (m, −b)	    -get_max(−x)

- Las queries no necesitan estar en orden.
- Como respuesta se toma el valor mayor (o menor) de todas las 
  posiciones del dp (a no ser que me pidan usar el elemento 'n' en la
  respuesta, en cuyo caso se toma 'dp_(n-1)').
  Si se permite no usar ningun elemento, tener en cuenta que la 
  respuesta podria ser '0' o algun elemento neutro.
*/

struct line {
    ll m, b;
    ll eval(ll x) const { return m * x + b; }
    ld inter(const line &l) const { return (ld)(b - l.b) / (l.m - m); }
};

struct cht {
    vector<line> lines;
    vector<ld> inter;
    int n;
    bool ok(const line &a, const line &b, const line &c) const {
        return a.inter(c) > a.inter(b);
    }
    void add(const line &l){
        n = sz(lines);
        if(n && lines.back().m == l.m && lines.back().b >= l.b) return;
        if(n == 1 && lines.back().m == l.m && lines.back().b < l.b) lines.pop_back(), n--;
        while(n >= 2 && !ok(lines[n-2], lines[n-1], l)){
            --n;
            lines.pop_back(); inter.pop_back();
        }
        lines.pb(l); n++;
        if(n >= 2) inter.pb(lines[n-2].inter(lines[n-1]));
    }
    ll get_max(ld x){
        if(lines.empty()) return LLONG_MIN;
        if(sz(lines) == 1) return lines[0].eval(x);
        int pos = lb(all(inter), x) - inter.begin();
        return lines[pos].eval(x);
    }
};

void solver(){ // Ejemplo con el caso de hallar maximos con pendientes ascendentes
    int n; cin>>n;
    // Si me dan 'm' desordenado, agrupar los 3 vectores en un vector {m, a, v} y ordenar 
    // (solo si ordenar se permite, de lo contrario usar CHT dinamico)
    vi v(n), a(n), m(n);
    for0(i,n) cin>>v[i];
    for0(i,n) cin>>a[i];
    for0(i,n) cin>>m[i];

    vi dp(n); dp[0] = v[0];
    cht h; h.add({m[0], dp[0]});

    for1(i,n-1){
        dp[i] = v[i] + max(0LL, h.get_max(a[i])); // max con '0' por si conviene no tomar ningun elemento anterior
        h.add({m[i], dp[i]});
    }
}