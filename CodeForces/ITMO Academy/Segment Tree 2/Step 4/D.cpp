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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ll gauss(ll n){
    if(n <= 0) return 0;
    return (n * (n+1)) / 2;
}

class segTree {
private:
    int size;
    vector<ll> lazy;
    vector<pll> tree;

    ll neutro = LLONG_MAX - 1;

    pll updateOp(pll a, ll b, int r, int l){
        assert(a.fi != neutro);
        if(b == neutro) return a;
        return {a.fi + b * (gauss(r-1) - gauss(l-1)), a.se + b * (ll)(r - l)};
    }

    ll updateOpL(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    pll calcOp(pll a, pll b){
        assert(a.fi != neutro || b.fi != neutro);
        if(a.fi == neutro) return b;
        if(b.fi == neutro) return a;
        return {a.fi + b.fi, a.se + b.se};
    }

    void applyUpdOp(pll &a, ll b, int r, int l){
        a = updateOp(a, b, r, l);
    }

    void applyUpdOpL(ll &a, ll b){
        a = updateOpL(a, b);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        applyUpdOpL(lazy[2*v + 1], lazy[v]);
        applyUpdOp(tree[2*v + 1], lazy[v], tm, tl);
        applyUpdOpL(lazy[2*v + 2], lazy[v]);
        applyUpdOp(tree[2*v + 2], lazy[v], tr, tm);
        lazy[v] = neutro;
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, ll val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOpL(lazy[v], val);
            applyUpdOp(tree[v], val, tr, tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    pll calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return {neutro, 0};
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        pll m1 = calc(l, r, 2*v + 1, tl, tm);
        pll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    // O(n)
    void build(vector<ll>& a, int v, int tl, int tr){ 
        if(tr == tl + 1){
            if(tl < sz(a)) tree[v] = {a[tl] * (ll)tl, a[tl]};
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
        tree.assign(2*size, {0LL, 0LL});
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    pll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vl a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    segTree st;
    st.init(n+1);
    st.build(a);
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val; cin>>l>>r>>val;
            st.update(l, r+1, val);
        }
        else{
            int l, r; cin>>l>>r;
            pll ans = st.calc(l, r+1);
            cout<<ans.fi - (ll)(l-1)*ans.se<<endl;
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