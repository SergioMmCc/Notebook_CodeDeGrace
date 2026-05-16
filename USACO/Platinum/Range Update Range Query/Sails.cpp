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

class segTree {
private:
    int size;
    vector<ll> lazy;
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
    void update(int l, int r, ll val, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            applyUpdOp(lazy[v], val, 1);
            applyUpdOp(tree[v], val, tr - tl);
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
        lazy.assign(2*size, neutro);
        tree.assign(2*size, 0LL);
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

ll gauss(ll n){
    return (n * (n-1)) >> 1;
}

void solver(){
    int n; cin>>n;
    vii a(n);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    sort(all(a));

    segTree st; st.init(1e5 + 2);
    st.update(1, a[0].se + 1, 1);

    for(int i = 1; i < n; i++){
        int h = a[i].fi, k = a[i].se;
        int pos = h - k + 1;
        ll val = st.calc(pos, pos+1);

        // Primer idx con a[pos] > a[idx]
        int l = pos+1, r = 1e5+1;
        while(l < r){
            int m = (l+r) / 2;
            if(st.calc(m, m+1) < val) r = m;
            else l = m+1;
        }

        if(r <= 1e5){
            int tope = min(h, r + k - 1);
            st.update(r, tope+1, 1);

            k -= tope - r + 1;

            if(!k) continue;
        }

        l = 1, r = pos;
        while(l < r){
            int m = (l+r) / 2;
            if(st.calc(m, m+1) <= val) r = m;
            else l = m+1;
        }

        st.update(r, r + k, 1);
    }

    ll ans = 0;
    for(int i = 1; i <= 1e5; i++){
        ll val = st.calc(i, i+1);
        ans += gauss(val);
    }

    cout<<ans<<endl;
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