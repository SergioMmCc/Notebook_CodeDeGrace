#include "../template.h"

// LiChao<T, MAX>: T = ll o ld, MAX = true para máximo, false para mínimo.
// - addLine(m, b)             recta completa               O(log n)
// - addLine(x1,y1,x2,y2)      recta por 2 puntos (solo flotante)
// - addSeg(m, b, xl, xr)      recta restringida a [xl,xr]  O(log^2 n)
// - addSegP(x1,y1,x2,y2)      segmento por 2 puntos (solo flotante)
// - query(x) devuelve -1 si no hay recta/segmento que cubra x, o si x no
//   está en xs. Asume que las respuestas reales nunca son -1.
// - Con ll cuidar que |m*x + b| quepa en ll. Con ld se usa eps = 1e-9.

template<class T, bool MX = false> struct LiChao{
    struct Line{
        T m, b;
        Line(): m(0), b(numeric_limits<T>::max()){}
        Line(T m, T b): m(m), b(b){}
        T operator()(T x)const{ return m * x + b; }
    };
    vector<T> xs;
    vector<Line> t;
    int n;

    static bool lt(T a, T b){
        if constexpr(is_floating_point<T>::value) return a < b - 1e-9;
        else return a < b;
    }

    LiChao(vector<T> v): xs(v){
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        n = sz(xs);
        t.assign(4 * max(n, 1), Line());
    }
    LiChao(ll l, ll r): xs(r - l + 1){
        iota(all(xs), (T)l);
        n = sz(xs);
        t.assign(4 * max(n, 1), Line());
    }
    LiChao(int m) : LiChao(0, m) {}

    void addLine(T m, T b){
        if(MX){ m = -m; b = -b; }
        if(n) insert(1, 0, n - 1, Line(m, b));
    }
    void addLine(T x1, T y1, T x2, T y2){
        static_assert(is_floating_point<T>::value, "addLine(2 puntos) requiere T flotante");
        if(x1 == x2) return;                      // recta vertical: no representable
        T m = (y2 - y1) / (x2 - x1);
        addLine(m, y1 - m * x1);
    }

    void addSeg(T m, T b, T xl, T xr){
        if(MX){ m = -m; b = -b; }
        int ia = lower_bound(all(xs), xl) - xs.begin();
        int ib = upper_bound(all(xs), xr) - xs.begin() - 1;
        if(ia <= ib) addRange(1, 0, n - 1, ia, ib, Line(m, b));
    }
    void addSegP(T x1, T y1, T x2, T y2){
        static_assert(is_floating_point<T>::value, "addSeg(2 puntos) requiere T flotante");
        if(x1 > x2){ swap(x1, x2); swap(y1, y2); }
        if(x1 == x2){ addSeg(0, MX ? max(y1, y2) : min(y1, y2), x1, x1); return; }
        T m = (y2 - y1) / (x2 - x1);
        addSeg(m, y1 - m * x1, x1, x2);
    }
   

    T query(T x){
        int i = lower_bound(all(xs), x) - xs.begin();
        if(i >= n || xs[i] != x) return -1;
        int v = 1, l = 0, r = n - 1;
        T res = numeric_limits<T>::max();
        while(true){
            res = min(res, t[v](x));
            if(l == r) break;
            int m = (l + r) / 2;
            if(i <= m){ v = 2 * v; r = m; }
            else{ v = 2 * v + 1; l = m + 1; }
        }
        // si el problema permite negativos, devolver un par <bool, T>
        if(res >= numeric_limits<T>::max() / 2) return -1;
        return MX ? -res : res;
    }

private:
    void insert(int v, int l, int r, Line nw){
        int m = (l + r) / 2;
        bool lef = lt(nw(xs[l]), t[v](xs[l]));
        bool mid = lt(nw(xs[m]), t[v](xs[m]));
        if(mid) swap(t[v], nw);
        if(l == r) return;
        if(lef != mid) insert(2 * v, l, m, nw);
        else insert(2 * v + 1, m + 1, r, nw);
    }
    void addRange(int v, int l, int r, int a, int b, Line nw){
        if(b < l || r < a) return;
        if(a <= l && r <= b){ insert(v, l, r, nw); return; }
        int m = (l + r) / 2;
        addRange(2 * v, l, m, a, b, nw);
        addRange(2 * v + 1, m + 1, r, a, b, nw);
    }
};
