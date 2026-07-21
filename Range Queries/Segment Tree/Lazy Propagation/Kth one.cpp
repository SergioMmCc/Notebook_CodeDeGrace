#include "../../../template.h"

/*
Segment Tree Lazy Propagation
- Halla el Kth one en 0-index, es decir, si me piden el indice del 0th one, me estan pididiendo el indice 
  del primer one. 
- El array tambien es 0-index, asi que si estuviera lleno de 1s, se considera que el
  0th 1 esta en la posicion 0.
- Las updates son de invertir (los 0s pasan a ser 1s y viceversa).
*/

private:
    int size;
    vector<bool> lazy;
    vector<int> tree;

    int updateOp(int a, int len){
        return len - a;
    }

    int calcOp(int a, int b){
        return a + b;
    }

    void applyUpdOp(int &a, int len){
        a = updateOp(a, len);
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || !lazy[v]) return;
        int tm = (tr + tl) / 2;
        lazy[2*v + 1] = !lazy[2*v + 1];
        lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(tree[2*v + 1], tm - tl);
        applyUpdOp(tree[2*v + 2], tr - tm);
        lazy[v] = 0;
    }

    // [l, r)
    void update(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            lazy[v] = 1;
            applyUpdOp(tree[v], tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, 2*v + 1, tl, tm);
        update(l, r, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // [l, r)
    int calc(int l, int r, int v, int tl, int tr, int idx){
        propagate(v, tl, tr);
        if(tr == tl + 1) return tl;

        int tm = (tl + tr) / 2;
        if(tree[2*v + 1] >= idx) return calc(l, r, 2*v + 1, tl, tm, idx);
        return calc(l, r, 2*v + 2, tm, tr, idx - tree[2*v + 1]);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, 0);
        tree.assign(2*size, 0);
    }
