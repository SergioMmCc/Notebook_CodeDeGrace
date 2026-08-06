#include "../../template.h"

/*
- Para problemas en los cuales no hay updates y se necesiten cosas como contar 
  diferentes, contar cantidad de elementos en un rango de valores o similares.
- Complejidad temporal de O(n*lg(n)) para build y O(lg(n)²) para update. 
  La complejidad espacial tambien es O(n*lg(n)).
- Segun esa informacion que se necesite, normalmente, se debe hacer binary 
  search. Entonces la complejidad de calculos suele ser O(lg(n)²).
Aplicaciones:
- Hallar la frecuencia de un numero en especifico en un rango.
- Hallar la cantidad de elementos mayores o menores a x en un rango.
- Hallar la cantidad de elementos entre [x, y] en un rango.
*/

class segTree{
private:
    int size;
    vector<vl> tree;
    vl neutro = {{}}; // Change

    vl calcOp(vl& a, vl& b){ // Change
        if(a == neutro) return b;
        if(b == neutro) return a;
        vl ans;
        int i = 0, j = 0;
        while(i < sz(a) || j < sz(b)){
            if(i >= sz(a) || (j < sz(b) && b[j] <= a[i])){
                ans.pb(b[j]);
                j++;
            }
            else{
                ans.pb(a[i]);
                i++;
            }
        }

        return ans;
    }

    ll calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return 0;
        if(tl >= l && tr <= r){
            // Para los calculos se deben usar cosas como 
            // el tamaño del vector, binary search, etc.
        }

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return m1 + m2;
    }

    void build(vl& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {{a[tl]}}; // Change
           return;
        }
        int tm = (tr + tl) / 2;
        build(a, 2*v + 1, tl, tm);
        build(a, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, {});
    }
    ll calc(int l, int r){return calc(l, r, 0, 0, size);}
    void build(vector<ll>& a){build(a, 0, 0, size);}
};