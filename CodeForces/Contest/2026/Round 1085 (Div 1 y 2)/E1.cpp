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
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<pll> lazy;
    vector<pll> tree;

    pll neutro = {LLONG_MAX - 1, 0LL};
    
    // Para query minimo y update suma
    pll updateOp(pll a, pll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return {a.fi + b.fi, a.se};
    }

    pll calcOp(pll a, pll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        if(a.fi == b.fi) return a.se > b.se ? a : b;
        return a.fi < b.fi ? a : b;
    }

    void applyUpdOp(pll &a, pll b, ll len){
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
            applyUpdOp(lazy[v], {val, 0}, 1);
            applyUpdOp(tree[v], {val, 0}, tr - tl);
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
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        pll m1 = calc(l, r, 2*v + 1, tl, tm);
        pll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    // O(n)
    void build(vector<pll>& a, int v, int tl, int tr){ 
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
        tree.assign(2*size, {0LL, 0LL});
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    pll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<pll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n; cin>>n;
    vi a(n), need(n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        need[i] = a[i] + i + 1 - n;
        maxx = max(maxx, a[i]);
    }
    if(maxx > n){
        cout<<"NO"<<endl;
        return;
    }
    n++;
    vector<vi> app(n);
    for(int i = 0; i < n-1; i++) app[a[i]].pb(i);
    vi current(n, 0);

    // Inicializar el segtree
    vll create(n, {1e11, 1e11});
    for(int i = 0; i < n-1; i++){
        create[a[i]] = min(create[a[i]], {need[i], a[i]});
    }
    segTree st; st.init(n); st.build(create);

    set<int> notUsed;
    for(int i = 0; i < 3*n; i++){
        notUsed.insert(i);
    }
    for(int i = 0; i < n-1; i++){
        if(notUsed.find(a[i]) != notUsed.end()) notUsed.erase(a[i]);
    }

    vi ans(n);
    for(int i = 0; i < n-1; i++){
        ll ne = st.calc(a[i], a[i]+1).fi;
        if(ne < 0 || ne > 1){
            // cout<<"i -> "<<i<<" ne -> "<<ne<<endl;
            cout<<"NO"<<endl;
            return;
        }

        pll mini = st.calc(0, n);
        if(!mini.fi){
            auto it = notUsed.ub((int)mini.se);
            ans[i] = *it;
            if(*it < n){
                st.update(*it, n, -1);
            }
            if(ne && *it > a[i]){
                cout<<"NO"<<endl;
                return;
            }
            notUsed.erase(it);
        }
        else{
            auto it = notUsed.begin();
            // cout<<"here i -> "<<i<<" it -> "<<*it<<endl;
            ans[i] = *it;
            if(*it < n){
                st.update(*it, n, -1);
            }
            if(*it > a[i]){
                cout<<"NO"<<endl;
                return;
            }
            notUsed.erase(it);
        }

        if(++current[a[i]] < sz(app[a[i]])){
            ll nextVal = need[app[a[i]][current[a[i]]]] - need[i];
            // cout<<"app -> "<<app[a[i]][current[a[i]]]<<" nextVal -> "<<nextVal<<endl;
            st.update(a[i], a[i]+1, nextVal);
        }
        else{
            st.update(a[i], a[i]+1, 1e14);
        }
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < n-1; i++) cout<<ans[i]<<' '; cout<<endl;
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