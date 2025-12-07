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
        return a + b;
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
        if(l >= r) return 0LL;
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n; cin>>n;
    vector<vector<int>> a(2*n + 1), b(2*n + 1);
    vector<int> c(n), d(n);

    for(int i = 0; i < n; i++){
        int num; cin>>num; num--;
        c[i] = num;
        a[num].pb(i);
    }
    for(int i = 0; i < n; i++){
        int num; cin>>num; num--;
        d[i] = num;
        b[num].pb(i);
    }

    segTree st;
    st.init(n);
    vector<ll> val(n);
    for(int i = 0; i < n; i++) val[i] = n - i;
    st.build(val);

    set<int> idx;
    vector<ll> ans(n);

    for(int num = 2*n - 1; num >= 0; num--){
        for(int y : b[num + 1]) st.update(y, 0LL);

        for(int x : a[num]){
            int l = c[x] == d[x] ? x : x + 1, r;
            ll add = 0;
            auto it = idx.ub(x);
            if(it == idx.end()) r = n;
            else{
                r = *it;
                add = ans[r];
            }

            add += st.calc(l, r);
            ans[x] = add;

            idx.insert(x);
        }
    }

    ll cnt = 0;
    for(ll an : ans) cnt += an;
    cout<<cnt<<endl;
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