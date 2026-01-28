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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<pli> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll updateOp(ll a, ll b, ll len, int op){ // op -> assign, !op -> suma
        if(op == -1) return neutro;
        if(b == neutro) return a;
        if(a == neutro) return b * len;
        return op ? b * len : a + b * len;
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || lazy[v].se == -1) return;
        int tm = (tr + tl) / 2;
        
        lazy[2*v + 1].fi = updateOp(lazy[2*v + 1].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 1].se == -1) lazy[2*v + 1].se = lazy[v].se;
        else lazy[2*v + 1].se = min(1, lazy[2*v + 1].se + lazy[v].se);

        tree[2*v + 1] = updateOp(tree[2*v + 1], lazy[v].fi, tm - tl, lazy[v].se);


        lazy[2*v + 2].fi = updateOp(lazy[2*v + 2].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 2].se == -1) lazy[2*v + 2].se = lazy[v].se;
        else lazy[2*v + 2].se = min(1, lazy[2*v + 2].se + lazy[v].se);

        tree[2*v + 2] = updateOp(tree[2*v + 2], lazy[v].fi, tm - tl, lazy[v].se);
        lazy[v] = {neutro, -1};
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, ll val, int v, int tl, int tr, int op){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            lazy[v] = {updateOp(lazy[v].fi, val, 1, op), op};
            tree[v] = updateOp(tree[v], val, tr - tl, op);
            return;
        }
        

        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm, op);
        update(l, r, val, 2*v + 2, tm, tr, op);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
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

    // O(n)
    void build(vector<ll>& a, int v, int tl, int tr){ 
        if(tr == tl + 1){
            tree[v] = a[tl];
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
        lazy.assign(2*size, {0LL, -1});
        tree.assign(2*size, 0LL);
    }

    void update(int l, int r, ll val, int op){
        update(l, r, val, 0, 0, size, op);
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, q; cin>>n>>q;
    segTree st;
    st.init(n);
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val; cin>>l>>r>>val;
            st.update(l, r, val, 1);
        }
        else if(op == 2){
            int l, r; ll val; cin>>l>>r>>val;
            st.update(l, r, val, 0);
        }
        else{
            int l, r; cin>>l>>r;
            cout<<st.calc(l, r)<<endl;
        }
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