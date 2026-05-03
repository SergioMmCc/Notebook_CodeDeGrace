#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{
    int val, seg;
    bool l, r;
};

class segTree {
private:
    int size;
    vector<node> lazy;
    vector<node> tree;

    node neutro = {INT32_MAX - 1, 0, 0, 0};

    node updateOp(node a, node b, ll len){
        if(b.val == neutro.val) return a;
        node ans = {(int)len * b.val, b.val, b.val, b.val};
        return ans;
    }

    node calcOp(node a, node b){
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val, a.seg + b.seg - (a.r == 1 && a.r == b.l ? 1 : 0), a.l, b.r};
        return ans;
    }

    void applyUpdOp(node &a, node b, ll len){
        a = updateOp(a, b, len);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        // Para Update de invertir (cambiar 0s por 1s y viceversa), usar:
        // lazy[2*v + 1] = !lazy[2*v + 1];
        // lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(lazy[2*v + 1], lazy[v], 1);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOp(lazy[2*v + 2], lazy[v], 1);
        applyUpdOp(tree[2*v + 2], lazy[v], tr - tm);
        lazy[v] = neutro;
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, int val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            node aux = {val, 1, val, val};
            applyUpdOp(lazy[v], aux, 1);
            applyUpdOp(tree[v], aux, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
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


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, neutro);
        tree.assign(2*size, {0LL, 0LL, 0LL, 0LL});
    }

    void update(int l, int r, int val){
        update(l, r, val, 0, 0, size);
    }

    node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

void solver(){
    int q; cin>>q;
    segTree st;
    st.init(1000001);
    while(q--){
        char c; int l, r; cin>>c>>l>>r;
        int val = c == 'B' ? 1 : 0;
        r += l;
        if(l > r) swap(l, r);
        l += 500000;
        r += 500000;

        st.update(l, r, val);
        node ans = st.calc(0, 1000001);
        cout<<ans.seg<<' '<<ans.val<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}