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

// Implementacion con array 0-index
/*
    - Esta implementacion es de suma, sin embargo, tambien podemos calcular 
      multiplicaciones (incluyendo multiplicacion modular y multiplicacion de 
      matrices), operaciones bitwise como and (&), or (|) y xor (^), gcd y cualquier 
      operacion que cumpla con la propiedad asociativa.
    - Se pueden contar minimos/maximos utilizando un par que guarde minimo, cantidad 
      de apariciones.
    - Nested segments:
      Para contar la cantidad de segmentos contenidos en otro se pueden recorrer los
      segmentos en order descendente de l, en ese momento se coloca se hace una querie
      de suma en su rango (ese valor es la cantidad de segmentos contenidos en este) y
      finalmente se actualiza su valor con 1 en r.
    - Intersecting Segments:
      Para hallar la cantidad de segmentos que se intersectan con otro, se recorren
      los puntos de cada segmento. Al llegar a una l, se marca esta posicion en 1. Al 
      llegar a r se marca la posicion en l con -1 y en r con 1 y se hace una querie de
      suma en (l, r) o [l, r], ese valor es la cantidad de segmentos que se intersectan
      con este.
*/

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
            cout<<st.calc(l, r).val<<endl;
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