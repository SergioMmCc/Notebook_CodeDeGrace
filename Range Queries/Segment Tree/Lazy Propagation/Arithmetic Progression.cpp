#include "../../../template.h"

/*
- Updates del tipo l, r, val, inc
  Basicamente hago a[l] += val, a[l+1] += val + inc, a[l+2] += val + 2*inc, hasta llegar a r-1.
- Queries de suma.
*/

ll gauss(ll n){
    return n <= 0 ? 0 : (n * (n + 1)) >> 1;
}

private:
    int size;
    vector<pll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll updateOp(ll a, pll b, ll len){
        if(b.fi == neutro) return a;
        assert(a != neutro);
        return a + b.fi * len + b.se * gauss(len - 1);
    }

    pll updateOpL(pll a, pll b, ll len){
        if(b.fi == neutro) return a;
        if(a.fi == neutro) return {b.fi + b.se * len, b.se};
        return {a.fi + b.fi + b.se * len, a.se + b.se};
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    void applyUpdOp(ll &a, pll b, ll len){
        a = updateOp(a, b, len);
    }

    void applyUpdOpL(pll &a, pll b, ll len){
        a = updateOpL(a, b, len);
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        applyUpdOpL(lazy[2*v + 1], lazy[v], 0);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOpL(lazy[2*v + 2], lazy[v], tm - tl);
        applyUpdOp(tree[2*v + 2], {lazy[v].fi + (ll)(tm - tl)*lazy[v].se, lazy[v].se}, tr - tm);
        lazy[v] = {neutro, 0};
    }

    // [l, r)
    void update(int l, int r, ll val, ll inc, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOpL(lazy[v], {val, inc}, tl - l);
            applyUpdOp(tree[v], {val + inc * (tl - l), inc}, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, inc, 2*v + 1, tl, tm);
        update(l, r, val, inc, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ 
        if(tr == tl + 1){
            if(tl < sz(a)) tree[v] = a[tl];
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
        lazy.assign(2*size, {neutro, 0});
        tree.assign(2*size, 0LL);
    }