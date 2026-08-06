#include "../../template.h"

// 0-index
// Implementacion ejemplo con suma
// Recordar que si los indices son muy grandes, cambiar SZ, L, R, etc, por ll
// Tener cuidado con el valor neutro ya que es comun que este sea el retorno en algunas calc
// Complejidad: O(lg(SZ)) para updates y calcs.

const int SZ = 1 << 30; // Techo del log2 del maximo indice
const ll neutro = LLONG_MAX - 1; // Change
const int LEN = 1e7; // tope de nodos totales (usar aprox lg(SZ) * q * 2)

struct node {
    ll val = neutro, lazy = neutro;
    int c[2] = {-1, -1};
};

class segTree {
private:
    vector<node> tree;
    int idx = 0;
    int root;

    // Para query suma y update assign
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        return b * len;
    }
    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b; // Change
    }
    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    int newNode(){
        tree[idx] = node();
        return idx++;
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tl + tr) / 2;
        if(tree[v].c[0] == -1) tree[v].c[0] = newNode();
        if(tree[v].c[1] == -1) tree[v].c[1] = newNode();

        int L = tree[v].c[0], R = tree[v].c[1];
        applyUpdOp(tree[L].lazy, tree[v].lazy, 1);
        applyUpdOp(tree[L].val, tree[v].lazy, tm - tl);
        applyUpdOp(tree[R].lazy, tree[v].lazy, 1);
        applyUpdOp(tree[R].val, tree[v].lazy, tr - tm);
        tree[v].lazy = neutro;
    }

    // [l, r)
    void update(int v, int l, int r, ll val, int tl, int tr){
        if(r <= tl || tr <= l) return;
        if(l <= tl && tr <= r){
            applyUpdOp(tree[v].lazy, val, 1);
            applyUpdOp(tree[v].val, val, tr - tl);
            return;
        }
        propagate(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(tree[v].c[0], l, r, val, tl, tm);
        update(tree[v].c[1], l, r, val, tm, tr);
        tree[v].val = calcOp(tree[tree[v].c[0]].val, tree[tree[v].c[1]].val);
    }

    // [l, r)
    ll calc(int v, int l, int r, int tl, int tr){
        if(r <= tl || tr <= l) return neutro;
        if(l <= tl && tr <= r) return tree[v].val;
        propagate(v, tl, tr);
        int tm = (tl + tr) / 2;
        ll lv = tree[v].c[0] != -1 ? calc(tree[v].c[0], l, r, tl, tm) : neutro;
        ll rv = tree[v].c[1] != -1 ? calc(tree[v].c[1], l, r, tm, tr) : neutro;
        return calcOp(lv, rv);
    }

public:
    void init(){
        tree.assign(LEN, node());
        idx = 0;
        root = newNode();
    }
    void update(int l, int r, ll val){ update(root, l, r, val, 0, SZ); }
    ll calc(int l, int r){ return calc(root, l, r, 0, SZ); }
};

void solver(){
    // Inicializar
    segTree st; st.init();

    // Update
    int l, r; ll val;
    st.update(l, r, val);

    // Calc
    int l, r; cin>>l>>r;
    ll ans = st.calc(l, r);
    cout<<(ans == neutro ? 0 : ans)<<endl;
}