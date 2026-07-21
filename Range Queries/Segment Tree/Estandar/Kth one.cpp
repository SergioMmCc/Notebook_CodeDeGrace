#include "../../../template.h"

/*
0-index
- Como usar:
  Si tengo un array con todo 1s, me va a decir que el 4to uno
  esta en la posicion 3. Asi que si me piden que diga el Kth
  uno en 0-index, es decir, donde el uno en la posicion 0
  es el primero, tengo que sumar 1 a k para cada query.
  Si me piden que diga el Kth uno en 1-index, puedo usar
  el valor normal de k.
- Sirve para ejercicios donde tenga que activar y desactivar
  posiciones, y contestar queries del tipo de cual es la Kth 
  posicion encendida.
*/

struct node{ // Change
    ll val; int idx;
};

private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1, INT_MAX - 1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val, 0};
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {val, tl}; // Change
            assert(tl == pos);
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr, int k){
        if(tl >= r || l >= tr) return neutro;
        if(tr - tl == 1) return tree[v];

        int tm = (tl + tr) / 2;
        if(tree[2*v + 1].val >= k) return calc(l, r, 2*v + 1, tl, tm, k);
        else return calc(l, r, 2*v + 2, tm, tr, k - tree[2*v + 1].val);
    }

    void build(vl& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {a[tl], tl}; // Change
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
        tree.assign(2*size, {0LL});
    }