#include "../../../template.h"

/*
- Para problemas en los cuales se necesite que cada nodo sea una estructura
  se puede tomar esta implementacion como base. La complejidad es la misma
  que la de un segment tree normal agregando un factor segun la complejidad 
  de las operaciones de insert y erase de la estructura utilizada. 
- Este ejemplo usando set tiene una complejidad de O(n*lg(n)) para build
  y O(lg(n)²) para update.
- Segun esa informacion que se necesite se debe hacer binary search, acceder a
  la clase del mapa, etc. Entonces la complejidad de calculos es variable, pero
  suele ser O(lg(n)²).
- Puede servir para problemas como hallar la frecuencia de un numero en
  especifico en un rango (en este caso tocaria usar map) o hallar si todos
  los numeros en un rango son diferentes (si bien existen formas mas eficientes
  de resolver este problema).
*/

struct node{ // Change
    set<ll> val;
};

private:
    int size;
    vector<node> tree;

    node neutro = {{}}; // Change

    node calcOp(node& a, node& b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = a;
        for(ll x : b.val) ans.val.insert(x);
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){
        if(tr - tl == 1){
            tree[v] = {{val}}; // Change
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){ // Change si walking on segment tree
        // Para los calculos se deben usar cosas como 
        // el tamaño del set, binary search sobre el set, 
        // etc.
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
        tree.assign(2*size, {{}});
    }