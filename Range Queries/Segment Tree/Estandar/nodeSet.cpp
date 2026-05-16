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
    Para problemas en los cuales se necesite que cada nodo sea una estructura
    se puede tomar esta implementacion como base. La complejidad es la misma
    que la de un segment tree normal agregando un factor segun la complejidad 
    de las operaciones de insert y erase de la estructura utilizada. 
    Este ejemplo usando set tiene una complejidad de O(n*lg(n)) para build
    y O(lg(n)^2) para update y calc.
    Puede servir para problemas como hallar la frecuenccia de un numero en
    especifico en un rango (en este caso tocaria usar map) o hallar si todos
    los numeros en un rango son diferentes (si bien existen formas mas eficientes
    de resolver este problema).
*/

struct node{ // Change
    set<ll> val;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {{}}; // Change

    node calcOp(node& a, node& b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = a;
        for(ll x : b.val) ans.val.insert(x);
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){
        if(tr - tl == 1){
            tree[v] = {{val}}; // Change
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

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
           if(tl < sz(a)) tree[v] = {{a[tl]}}; // Change
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
        tree.assign(2*size, {{}});
        // build(0, 0, size);
    }

    void update(int pos, ll val){
        update(pos, val, 0, 0, size);
    }

    node calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vl a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    segTree st;
    st.init(n);
    st.build(a);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i; ll v; cin>>i>>v;
            st.update(i, v);
        }
        else{
            int l, r; cin>>l>>r;
            node ans = st.calc(l, r);
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