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

struct node{ // Change
    int l, r;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {-1, -1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.l == neutro.l) return b;
        if(b.l == neutro.l) return a;
        node ans = {a.l + b.l - min(a.l, b.r), a.r + b.r - min(a.l, b.r)};
        return ans;
    }

    void update(int pos, bool val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            if(val) tree[v] = {0, 1}; // Change
            else tree[v] = {1, 0};
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

    void build(vb& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)){
            if(a[tl]) tree[v] = {0, 1}; // Change
            else tree[v] = {1, 0};
           }
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

    void update(int pos, bool val){
        update(pos, val, 0, 0, size);
    }

    node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vb& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    string s; cin>>s;
    int n = sz(s);
    vb a(n+1);
    for(int i = 1; i <= n; i++) a[i] = s[i-1] == '1';

    segTree st; st.init(n+1); st.build(a);

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int idx; cin>>idx;
            a[idx] = !a[idx];
            st.update(idx, a[idx]);
        }
        else{
            int l, r; cin>>l>>r; r++;
            node aux = st.calc(l, r);
            cout<<aux.l + aux.r<<endl;
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