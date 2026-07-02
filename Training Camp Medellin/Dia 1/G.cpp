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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{ // Change
    ll val;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val};
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {val}; // Change
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr){ // Change si walking on segment tree
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v]; // si walking on seg tree -> tr - tl == 1

        int tm = (tl + tr) / 2;
        node m1 = calc(l, r, 2*v + 1, tl, tm);
        node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vl& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {a[tl]}; // Change
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
        tree.assign(2*size, {0LL});
        // build(a, 0, 0, size);
    }

    void update(int pos, ll val){
        update(pos, val, 0, 0, size);
    }

    node calc(int l, int r){
        if(l == r) return {0};
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

int chToInt(char c){
    int aux = (int)c;
    if(aux >= '0' && aux <= '9') return aux - '0';
    if(aux >= 'a' && aux <= 'z') return aux + 10 - 'a';
    return aux + 36 - 'A';
}

char intToCh(int idx){
    if(idx < 10) return (char)(idx + '0');
    if(idx < 36) return (char)(idx - 10 + 'a');
    return (char)(idx - 36 + 'A');
}

void solver(){
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<indexed_set> a(62);
    for(int i = 0; i < n; i++) a[chToInt(s[i])].insert(i+1);

    // for(int i = 0; i < 62; i++){
    //     cout<<"i -> "<<i<<": ";
    //     for(int x : a[i]) cout<<x<<' ';
    //     cout<<endl;
    // }

    segTree st; st.init(n+1);
    while(q--){
        int l, r; char c; cin>>l>>r>>c;
        int let = chToInt(c);
        if(a[let].empty()) continue;
        int aux = *a[let].find_by_order(sz(a[let]) - 1);
        if(aux - st.calc(1, aux).val < l) continue;

        // cout<<"l -> "<<l<<" r -> "<<r<<" c -> "<<c<<" let -> "<<let<<" sz -> "<<sz(a[let])<<endl;

        int lo = 0, hi = sz(a[let]) - 1;
        while(lo < hi){
            int mid = (hi + lo) / 2;
            int idx = *a[let].find_by_order(mid);
            // cout<<"mid -> "<<mid<<" idx -> "<<idx<<" calc -> "<<st.calc(1, idx).val<<endl;
            if(idx - st.calc(1, idx).val >= l) hi = mid;
            else lo = mid+1;
        }
        // cout<<"hi -> "<<hi<<" which -> "<<*a[let].find_by_order(hi)<<endl;

        stack<int> del;
        while(hi < sz(a[let])){
            int idx = *a[let].find_by_order(hi);
            if(idx - st.calc(1, idx).val > r) break;
            del.push(idx);
            hi++;
        }

        while(!del.empty()){
            int idx = del.top(); del.pop();
            // cout<<"erase -> "<<idx<<endl;
            a[let].erase(idx);
            st.update(idx, 1);
        }
    }

    set<pair<int, char>> ans;
    for(int i = 0; i < 62; i++){
        char c = intToCh(i);
        for(int x : a[i]){
            ans.insert({x, c});
        }
    }

    for(auto aux : ans) cout<<aux.se;
    cout<<endl;
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