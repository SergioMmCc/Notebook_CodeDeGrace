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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return min(a, b);
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = val;
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
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
        tree.assign(2*size, 0LL);
        // build(0, 0, size);
    }

    void update(int pos, ll val){
        update(pos, val, 0, 0, size);
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
    vector<vector<int>> idx(n+1);
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        idx[num].pb(i);
    }

    set<int> add1, add2;
    vector<ll> create(n, n);
    for(int i = 1; i <= n; i++){
        vector<int> plus;
        for(int j : idx[i]){
            auto it = add1.ub(j);
            if(it != add1.end()){
                int k = *it;
                plus.pb(k);
                auto it2 = add2.ub(k);
                if(it2 != add2.end()) create[j] = *it2;
            }
        }

        for(int x : plus) add2.insert(x);
        for(int j : idx[i]) add1.insert(j);
    }

    segTree st;
    st.init(n);
    st.build(create);

    while(q--){
        int l, r; cin>>l>>r;
        l--;
        int num = st.calc(l, r);
        cout<<(num >= r ? "YES" : "NO")<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}