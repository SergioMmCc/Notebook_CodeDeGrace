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

struct node{
    ll val, pre, suf, sum;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1, LLONG_MAX - 1, LLONG_MAX - 1, LLONG_MAX - 1};

    node calcOp(node a, node b){
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans;
        ans.val = max(max(0LL, a.suf + b.pre), max(a.val, b.val));
        ans.pre = max(0LL, max(a.pre, a.sum + b.pre));
        ans.suf = max(0LL, max(b.suf, a.suf + b.sum));
        ans.sum = a.sum + b.sum;
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {max(0LL, val), max(0LL, val), max(0LL, val), val};
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        node m1 = calc(l, r, 2*v + 1, tl, tm);
        node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {max(0LL, a[tl]), max(0LL, a[tl]), max(0LL, a[tl]), a[tl]};
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
        // build(0, 0, size);
    }

    void update(int pos, ll val){
        update(pos, val, 0, 0, size);
    }

    node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vl& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vl a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    segTree st; st.init(n);
    st.build(a);

    node ans = st.calc(0, n);
    cout<<ans.val<<endl;

    while(m--){
        int idx; ll val; cin>>idx>>val;
        st.update(idx, val);
        ans = st.calc(0, n);
        cout<<ans.val<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}