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

struct Node{
    int minn, maxx, ans;
};

class segTree {
private:
    int size;
    vector<Node> tree;

    Node neutro = {INT32_MAX - 1, INT32_MAX - 1, INT32_MAX - 1};

    Node calcOp(Node a, Node b){
        if(a.minn == neutro.minn) return b;
        if(b.minn == neutro.minn) return a;
        return {min(a.minn, b.minn), max(a.maxx, b.maxx), max(max(a.ans, b.ans), b.maxx - a.minn)};
    }

    void update(int pos, int val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v].minn = tree[v].maxx = val;
            tree[v].ans = 0;
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    Node calc(int l, int r, int v, int tl, int tr){
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        Node m1 = calc(l, r, 2*v + 1, tl, tm);
        Node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<int>& a, int v, int tl, int tr){ // O(n)
        if(tr - tl == 1){
           if(tl < sz(a)) tree[v].minn = tree[v].maxx = a[tl];
           tree[v].ans = 0;
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
        tree.assign(2*size, neutro);
        // build(0, 0, size);
    }

    void update(int pos, int val){
        update(pos, val, 0, 0, size);
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size).ans;
    }

    void build(vector<int>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, q; cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<int> ra = a;
    reverse(all(ra));

    for(int i = 0; i < n; i++) a[i] -= i, ra[i] -= i;

    segTree st, rst;
    st.init(n); rst.init(n);
    st.build(a); rst.build(ra);

    cout<<max(st.calc(0, n), rst.calc(0, n))<<endl;
    while(q--){
        int p, x; cin>>p>>x; p--;
        st.update(p, x - p); rst.update(n - p - 1, x - n + p + 1);
        cout<<max(st.calc(0, n), rst.calc(0, n))<<endl;
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