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

/* 
   Sirve para hallar el primer j tal que j > l y a[j] > x.
   Si simplemente se quiere hallar el primer indice en
   cualquier parte del array, se envia a la funcion query
   un valor de l = 0.
*/

struct node{ // Change
    ll val; int idx;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1, -1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans;
        if(a.val >= b.val) ans = a;
        else ans = b;
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {val, tl}; // Change
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr, int x){
        if(tl >= r || l >= tr) return neutro;
        if(tr - tl == 1){
            if(tree[v].val < x) return neutro;
            return tree[v];
        }

        int tm = (tl + tr) / 2;
        node ans = neutro;
        if(tree[2*v + 1].val >= x) ans = calc(l, r, 2*v + 1, tl, tm, x);
        if(ans.idx == neutro.idx && tree[2*v + 2].val >= x) ans = calc(l, r, 2*v + 2, tm, tr, x);
        return ans;
    }

    void build(vl& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v] = {a[tl], tl}; // Change
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

    node calc(int l, int r, int x){
        return calc(l, r, 0, 0, size, x);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    segTree st; st.init(n);
    st.build(a);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i, v; cin>>i>>v;
            st.update(i, v);
        }
        else{
            int x, l; cin>>x>>l;
            cout<<st.calc(l, n, x).idx<<endl;
        }
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