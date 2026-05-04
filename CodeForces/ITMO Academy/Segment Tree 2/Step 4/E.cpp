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

class segTree {
private:
    int size;
    vector<pll> lazy;
    vector<ll> tree;

    pll neutro = {1e5 + 1, -1};

    ll updateOp(ll a, pll b){
        if(b.fi == neutro.fi) return a;
        ll ans = max(min(a, b.fi), b.se);
        return ans;
    }

    pll updateOpL(pll a, pll b){
        if(b.fi == neutro.fi) return a;
        if(b.fi < a.se) return {b.fi, b.fi};
        if(b.se > a.fi) return {b.se, b.se};
        return {min(a.fi, b.fi), max(a.se, b.se)};
    }

    ll calcOp(ll a, ll b){
        if(a == neutro.fi) return b;
        return a;
    }

    void applyUpdOp(ll &a, pll b){
        a = updateOp(a, b);
    }

    void applyUpdOpL(pll &a, pll b){
        a = updateOpL(a, b);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        // Para Update de invertir (cambiar 0s por 1s y viceversa), usar:
        // lazy[2*v + 1] = !lazy[2*v + 1];
        // lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOpL(lazy[2*v + 1], lazy[v]);
        applyUpdOp(tree[2*v + 1], lazy[v]);
        applyUpdOpL(lazy[2*v + 2], lazy[v]);
        applyUpdOp(tree[2*v + 2], lazy[v]);
        lazy[v] = neutro;
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, pll val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOpL(lazy[v], val);
            applyUpdOp(tree[v], val);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro.fi;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, {1e5, 0});
        tree.assign(2*size, 0LL);
    }

    void update(int l, int r, pll val){
        update(l, r, val, 0, 0, size);
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    while(m--){
        int op, l, r; pll val = {1e5, 0}; cin>>op>>l>>r; r++;
        if(op == 1) cin>>val.se;
        else cin>>val.fi;

        st.update(l, r, val);
    }

    for(int i = 0; i < n; i++) cout<<st.calc(i, i+1)<<endl;
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