#include "../template.h"

/*
- 0-index, se usa exactamente igual que el recursivo.
- Un poco más eficiente que el recursivo.
- El vector que se mande en el build debe tener tamaño igual al
  parametro que se manda en el init.
- Usar para consultas simples como sum, min, max, xor, gcd, etc.
*/

struct segTree{
    int n; ll neutro = LLONG_MAX - 1; // CHANGE neutro
    vl tree;
    inline ll op(ll a, ll b){ return min(a, b); } // CHANGE
    void init(int _n){
        n = _n;
        tree.assign(2*n, neutro);
    }
    void build(vl& a){
        for0(i, n) tree[n + i] = a[i];
        forrl(i, 1, n-1) tree[i] = op(tree[i<<1], tree[i<<1|1]);
    }
    ll calc(int l, int r){  // [l, r)
        ll resL = neutro, resR = neutro;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) resL = op(resL, tree[l++]);
            if(r&1) resR = op(tree[--r], resR);
        }
        return op(resL, resR);
    }
    void update(int p, ll val){  // set val at position p (0 - idx)
        for(tree[p += n] = val; p > 1; p >>= 1) tree[p>>1] = op(tree[p], tree[p^1]);
    }
};