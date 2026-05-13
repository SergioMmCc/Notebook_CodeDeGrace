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
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

/*
    Updates del tipo l, r, val, inc
    Basicamente hago a[l] += val, a[l+1] += val + inc, a[l+2] += val + 2*inc, hasta llegar a r-1

    Queries de suma 
*/

ll gauss(ll n){
    return n <= 0 ? 0 : (n * (n + 1)) >> 1;
}

class segTree {
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

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        applyUpdOpL(lazy[2*v + 1], lazy[v], 0);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOpL(lazy[2*v + 2], lazy[v], tm - tl);
        applyUpdOp(tree[2*v + 2], {lazy[v].fi + (ll)(tm - tl)*lazy[v].se, lazy[v].se}, tr - tm);
        lazy[v] = {neutro, 0};
    }

    // O(lg(n))
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

    void update(int l, int r, ll val, ll inc){
        update(l, r, val, inc, 0, 0, size);
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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    segTree st;
    st.init(n);
    st.build(a);

    while(q--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val, inc; cin>>l>>r>>val>>inc; 
            l--; // Para convertirlo en 0-index
            st.update(l, r, val, inc);
        }
        else{
            int l, r; cin>>l>>r; l--;
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