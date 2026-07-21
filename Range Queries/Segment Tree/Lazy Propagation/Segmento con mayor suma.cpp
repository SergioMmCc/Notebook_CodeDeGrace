#include "../../../template.h"

// Update de asignacion, query de segmento con mayor suma
// La respuesta se guarda en .seg

struct Node{
    ll seg, pref, suf, sum;
};

private:
    int size;
    vector<Node> lazy;
    vector<Node> tree;

    Node neutro = {0LL, 0LL, 0LL, LLONG_MAX - 1};

    Node updateOp(Node a, Node b, ll len){
        if(b.sum == neutro.sum) return a;
        Node ans = {0LL, 0LL, 0LL, 0LL};
        ans.sum = b.sum * len;
        if(b.sum > 0LL) ans.seg = ans.suf = ans.pref = ans.sum;

        return ans;
    }

    Node calcOp(Node a, Node b){
        if(a.sum == neutro.sum) return b;
        if(b.sum == neutro.sum) return a;
        Node ans;
        ans.seg = max(0LL, max(max(a.seg, b.seg), a.suf + b.pref));
        ans.pref = max(0LL, max(a.pref, a.sum + b.pref));
        ans.suf = max(0LL, max(b.suf, b.sum + a.suf));
        ans.sum = a.sum + b.sum;

        return ans;
    }

    void applyUpdOp(Node &a, Node b, ll len){
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
            Node x = {0LL, 0LL, 0LL, val};
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
    Node calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        Node m1 = calc(l, r, 2*v + 1, tl, tm);
        Node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, neutro);
        tree.assign(2*size, neutro);
    }