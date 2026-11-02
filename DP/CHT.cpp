#include "../template.h"

/*
- Tabla para saber como hacer las queries segun el caso que se busca:
Problema	Pendientes	    Recta	    Query	Respuesta
max	        ascendentes	    (m, b)	    x	    get_max(x)
min	        descendentes	(−m, −b)	x	    -get_max(x)
max	        descendentes	(−m, b)	    −x	    get_max(−x)
min	        ascendentes	    (m, −b)	    −x	    -get_max(−x)
*/

struct line {
    ll m, b;
    ll eval(ll x) { return m * x + b; }
    ld inter(line &l) { return (ld) (b - l.b) / (l.m - m); }
};

struct cht {
    vector<line> lines;
    vector<ld> inter;
    int n;
    inline bool ok(line &a, line &b, line &c){
        return a.inter(c) > a.inter(b);
    }
    void add(line &l){ // m1 < m2 < m3 ...
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

void solver(){

}