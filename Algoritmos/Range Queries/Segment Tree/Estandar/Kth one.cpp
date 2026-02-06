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


// 0-index
// - Para este tipo de ejercicios en que se pide hallar en que 
//   posicion se encuentra algo se utiliza una tecnica que se 
//   llama walking on segment tree, entonces en las querys no
//   hago una operacion entre el resultado de los 2 hijos sino
//   que me dirijo hacia uno de ellos segun alguna condicion.
//   La condicion de parada tambien cambia, pues ahora se sigue
//   explorando el arbol no hasta que los parametros de consulta
//   encajen con los del llamado actual a la funcion, sino hasta
//   que el nodo que se esta explorando corresponda a un segmento 
//   de tamaño uno.
// - Como usar:
//   Si tengo un array con todo 1s, me va a decir que el 4to uno
//   esta en la posicion 3. Asi que si me piden que diga el Kth
//   uno en 0-index, es decir, donde el uno en la posicion 0
//   es el primero, tengo que sumar 1 a k para cada query.
//   Si me piden que diga el Kth uno en 1-index, puedo usar
//   el valor normal de k
// - Sirve para ejercicios donde tenga que activar y desactivar
//   posiciones, y contestar queries del tipo de cual es la Kth 
//   posicion encendida

struct node{ // Change
    ll val; int idx;
};

class segTree {
private:
    int size;
    vector<node> tree;

    node neutro = {LLONG_MAX - 1, INT_MAX - 1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val, 0};
        return ans;
    }

    void update(int pos, ll val, int v, int tl, int tr){ // O(lg(n))
        if(tr - tl == 1){
            tree[v] = {val, tl}; // Change
            assert(tl == pos);
            return;
        }
        
        int tm = (tl + tr) / 2;
        if(pos < tm) update(pos, val, 2*v + 1, tl, tm);
        else update(pos, val, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }

    // O(lg(n))
    // [l, r)
    node calc(int l, int r, int v, int tl, int tr, int k){
        if(tl >= r || l >= tr) return neutro;
        if(tr - tl == 1) return tree[v];

        int tm = (tl + tr) / 2;
        if(tree[2*v + 1].val >= k) return calc(l, r, 2*v + 1, tl, tm, k);
        else return calc(l, r, 2*v + 2, tm, tr, k - tree[2*v + 1].val);
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

    node calc(int l, int r, int k){
        return calc(l, r, 0, 0, size, k);
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

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i; cin>>i;
            a[i] = 1 ^ a[i];
            st.update(i, a[i]);
        }
        else{
            int k; cin>>k; k++;
            cout<<st.calc(0, n, k).idx<<endl;
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