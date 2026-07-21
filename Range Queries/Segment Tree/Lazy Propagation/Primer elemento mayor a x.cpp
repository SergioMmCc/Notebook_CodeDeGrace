#include "../../../template.h"

/*
- Se hacen querys l, x, donde se retorna el indice (0-index) del primer elemento que cumpla 
  i >= l && a[i] >= x.
- En esta implemetacion se usan updates de suma.
*/

private:
    int size;
    vector<ll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return a + b;
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return max(a, b);
    }

    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        applyUpdOp(lazy[2*v + 1], lazy[v], 1);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOp(lazy[2*v + 2], lazy[v], 1);
        applyUpdOp(tree[2*v + 2], lazy[v], tr - tm);
        lazy[v] = neutro;
    }

    // [l, r)
    void update(int l, int r, ll val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOp(lazy[v], val, 1);
            applyUpdOp(tree[v], val, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // [l, r)
    int calc(int l, int r, int v, int tl, int tr, ll x){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return -1;
        if(tr == tl + 1){
            return tl;
        }

        int tm = (tl + tr) / 2;
        int ans = -1;
        if(tree[2*v + 1] >= x) ans = calc(l, r, 2*v + 1, tl, tm, x);
        if(ans == -1 && tree[2*v + 2] >= x) ans = calc(l, r, 2*v + 2, tm, tr, x);
        return ans;
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, 0LL);
        tree.assign(2*size, 0LL);
    }