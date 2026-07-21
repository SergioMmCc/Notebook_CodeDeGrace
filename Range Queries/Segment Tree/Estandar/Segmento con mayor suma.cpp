#include "../../../template.h"

struct node{
    ll val, pre, suf, sum;
};


private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1, LLONG_MAX - 1, LLONG_MAX - 1, LLONG_MAX - 1};

    node calcOp(node a, node b){
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans;
        ans.val = max(max(0LL, a.suf + b.pre), max(a.val, b.val));
        ans.pre = max(0LL, max(a.pre, a.sum + b.pre));
        ans.suf = max(0LL, max(b.suf, a.suf + b.sum));
        ans.sum = a.sum + b.sum;
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {max(0LL, val), max(0LL, val), max(0LL, val), val};
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        node m1 = calc(l, r, 2*v + 1, tl, tm);
        node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {max(0LL, a[tl]), max(0LL, a[tl]), max(0LL, a[tl]), a[tl]};
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
        tree.assign(2*size, {0LL, 0LL, 0LL, 0LL});
    }
