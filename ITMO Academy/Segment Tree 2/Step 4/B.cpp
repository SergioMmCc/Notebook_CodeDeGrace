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
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<pll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;
    
    // Para query minimo y update suma
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return a + b;
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return min(a, b);
    }

    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(lazy[v].fi == neutro) return;
        if(tr == tl + 1){
            tree[v] += lazy[v].fi;
            lazy[v] = {neutro, 0LL};
            return;
        }
        int tm = (tr + tl) / 2;
        
        lazy[2*v + 1].fi = updateOp(lazy[2*v + 1].fi, lazy[v].fi, 1);
        lazy[2*v + 1].se += lazy[v].se;
        
        lazy[2*v + 2].fi = updateOp(lazy[2*v + 2].fi, lazy[v].fi + lazy[v].se * (tm - tl), 1);
        lazy[2*v + 2].se += lazy[v].se;

        tree[v] += lazy[v].fi;

        lazy[v] = {neutro, 0};
    }

    // O(lg(n))
    // [l, r)
    void update(int l, int r, ll val, ll inc, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            lazy[v] = {val + inc * (tl - l), inc};
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
        lazy.assign(2*size, {neutro, 0LL});
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
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val, inc; cin>>l>>r>>val>>inc; l--;
            st.update(l, r, val, inc);
        }
        else{
            int idx; cin>>idx; idx--;
            cout<<st.calc(idx, idx + 1)<<endl;
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