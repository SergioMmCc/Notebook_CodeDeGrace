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

class segTree {
private:
    int size;
    vector<ll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return a + b;
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return max(a, b);
    }

    void applyUpdOp(ll &a, ll b, ll len){
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
    int calc(int l, int r, int v, int tl, int tr, ll x){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return -1;
        if(tr == tl + 1){
            return tl;
        }

        int tm = (tl + tr) / 2;
        int ans = -1;
        if(tree[2*v + 1] >= x) ans = calc(l, r, 2*v + 1, tl, tm, x);
        if(ans == -1 && tree[2*v + 2] >= x) ans = calc(l, r, 2*v + 2, tm, tr, x);
        return ans;
    }

    // O(n)
    // void build(int v, int tl, int tr){ 
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
        lazy.assign(2*size, 0LL);
        tree.assign(2*size, 0LL);
        // build(0, 0, size);
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    int calc(int l, int r, ll x){
        return calc(l, r, 0, 0, size, x);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    segTree st;
    st.init(n);
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r; ll val; cin>>l>>r>>val;
            st.update(l, r, val);
        }
        else{
            ll x; int l; cin>>x>>l;
            cout<<st.calc(l, n, x)<<endl;
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