#include "../../template.h"

// Update de asignacion, query de segmento con mayor suma
// La respuesta se guarda en .val

struct node{
    ll val, pref, suf, sum;
};

class segTree{
private:
    int size;
    vector<node> lazy;
    vector<node> tree;

    node neutro = {0LL, 0LL, 0LL, LLONG_MAX - 1};

    node updateOp(node a, node b, ll len){
        if(b.sum == neutro.sum) return a;
        node ans = {0LL, 0LL, 0LL, 0LL};
        ans.sum = b.sum * len;
        if(b.sum > 0LL) ans.val = ans.suf = ans.pref = ans.sum;

        return ans;
    }

    node calcOp(node a, node b){
        if(a.sum == neutro.sum) return b;
        if(b.sum == neutro.sum) return a;
        node ans;
        ans.val = max(0LL, max(max(a.val, b.val), a.suf + b.pref));
        ans.pref = max(0LL, max(a.pref, a.sum + b.pref));
        ans.suf = max(0LL, max(b.suf, b.sum + a.suf));
        ans.sum = a.sum + b.sum;

        return ans;
    }

    void applyUpdOp(node &a, node b, ll len){
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
            node x = {0LL, 0LL, 0LL, val};
            applyUpdOp(lazy[v], x, 1);
            applyUpdOp(tree[v], x, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // [l, r)
    node calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        node m1 = calc(l, r, 2*v + 1, tl, tm);
        node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vl& a, int v, int tl, int tr){ 
        if(tr == tl + 1){
            if(tl < sz(a)) tree[v] = tree[v] = {max(0LL, a[tl]), max(0LL, a[tl]), max(0LL, a[tl]), a[tl]};
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
        lazy.assign(2*size, neutro);
        tree.assign(2*size, neutro);
    }
    void update(int l, int r, ll val){update(l, r, val, 0, 0, size);}
    node calc(int l, int r){return calc(l, r, 0, 0, size);}
    void build(vl& a){build(a, 0, 0, size);}
};