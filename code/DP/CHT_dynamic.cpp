#include "../template.h"

/* NO TESTED
CHT dinamico (no importa el orden en que se agregan las rectas).
- Complejidad: add O(log(n)), get_max O(log(n)).
- Uso tipico para dp en arboles con small-to-large.
- Solo para 'x' entero.
*/

struct line {
    ll m, b;
    mutable ll p;                       // óptima para x <= p
    bool operator<(const line &o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

struct dyn_cht : multiset<line, less<>> {
    static ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // piso

    // fija x->p (frontera con y); true si x tapa por completo a y
    bool isect(iterator x, iterator y){
        if(y == end()) { x->p = INFL; return false; }
        if(x->m == y->m) x->p = (x->b > y->b ? INFL : -INFL);
        else x->p = fdiv(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }
    void add(ll m, ll b){
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);                    // limpia a la derecha
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)       // limpia a la izquierda
            isect(x, erase(y));
    }
    ll get_max(ll x){ // Falla si el hull esta vacio
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.b;
    }
};

void solver(){
    dyn_cht h;

    // Uso para maximo
    h.add(m, b);          // en cualquier orden de pendientes
    ll v = h.get_max(x);  // x en cualquier orden, intercalado con add
    
    // Uso para minimo
    h.add(-m, -b);
    ll v = -h.get_max(x);
}