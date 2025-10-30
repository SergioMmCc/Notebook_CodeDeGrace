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

// Segment Tree Lazy Propagation
// - Es necesario que se cumpla la propiedad asociativa tanto en las operaciones de update como calc.
// - Es necesario que se cumpla que calcOp(updateOp(a, x), updateOp(b, x)) == updateOp(calcOp(a, b), x),
//   es decir, que updateOp sea distributiva relativa a calcOp, ejemplo, update de multiplicacion, calc
//   suma. En caso de que no se cumpla esa propiedad (update assign, calc suma o update suma, calc suma),
//   se debe ajustar utilizando la longitud del rango en la operacion update. 
// - Este ejemplo corresponde a update assign y calc suma.


struct Node{
    ll seg, pref, suf, sum;
};

class segTree {
private:
    int size;
    vector<Node> lazy;
    vector<Node> tree;

    Node neutro = {0LL, 0LL, 0LL, LLONG_MAX - 1};

    Node updateOp(Node a, Node b, ll len){
        if(b.sum == neutro.sum) return a;
        Node ans = {0LL, 0LL, 0LL, 0LL};
        ans.sum = b.sum * len;
        if(b.sum > 0LL) ans.seg = ans.suf = ans.pref = ans.sum;

        return ans;
    }

    Node calcOp(Node a, Node b){
        if(a.sum == neutro.sum) return b;
        if(b.sum == neutro.sum) return a;
        Node ans;
        ans.seg = max(0LL, max(max(a.seg, b.seg), a.suf + b.pref));
        ans.pref = max(0LL, max(a.pref, a.sum + b.pref));
        ans.suf = max(0LL, max(b.suf, b.sum + a.suf));
        ans.sum = a.sum + b.sum;

        return ans;
    }

    void applyUpdOp(Node &a, Node b, ll len){
        a = updateOp(a, b, len);
    }

    // O(1)
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
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
            Node x = {0LL, 0LL, 0LL, val};
            applyUpdOp(lazy[v], x, 1);
            applyUpdOp(tree[v], x, tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, val, 2*v + 1, tl, tm);
        update(l, r, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    Node calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        Node m1 = calc(l, r, 2*v + 1, tl, tm);
        Node m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    // void build(int v, int tl, int tr){ // O(n)
    //     if(tr == tl + 1){
    //         tree[v] = 1;
    //         return;
    //     }
    //     int tm = (tr + tl) / 2;
    //     build(2*v + 1, tl, tm);
    //     build(2*v + 2, tm, tr);
    //     tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    // }


public:
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        lazy.assign(2*size, {0LL, 0LL, 0LL, 0LL});
        tree.assign(2*size, {0LL, 0LL, 0LL, 0LL});
        // build(0, 0, size);
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    Node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    while(m--){
        int l, r; ll val; cin>>l>>r>>val;
        st.update(l, r, val);
        cout<<st.calc(0, n).seg<<endl;
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