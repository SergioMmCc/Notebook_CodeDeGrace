#include "../../../template.h"

/*
Segment Tree Lazy Propagation (ejemplo con update assign y calc suma).
- Es necesario que se cumpla la propiedad asociativa tanto en las operaciones de update como calc.
- Es necesario que se cumpla que calcOp(updateOp(a, x), updateOp(b, x)) == updateOp(calcOp(a, b), x),
  es decir, que updateOp sea distributiva relativa a calcOp, ejemplo, update de multiplicacion, calc
  suma. En caso de que no se cumpla esa propiedad (update assign, calc suma o update suma, calc suma),
  se debe ajustar utilizando la longitud del rango en la operacion update. 
- Si se llega a pedir update de diferentes tipos, toca tener cuidado con la propagacion. Ejemplo con
  update de asignacion (operacion identificada con 1) y de suma (operacion identificada con 0):
    Updates:
    ll updateOp(ll a, ll b, ll len, int op){ // op -> assign, !op -> suma
        if(op == -1) return neutro;
        if(b == neutro) return a;
        if(a == neutro) return b * len;
        return op ? b * len : a + b * len;
    }
    Propagacion:
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || lazy[v].se == -1) return;
        int tm = (tr + tl) / 2;
        
        lazy[2*v + 1].fi = updateOp(lazy[2*v + 1].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 1].se == -1) lazy[2*v + 1].se = lazy[v].se;
        else lazy[2*v + 1].se = min(1, lazy[2*v + 1].se + lazy[v].se); // La asignacion prevalece ya que se le suma al valor que se debe asignar

        tree[2*v + 1] = updateOp(tree[2*v + 1], lazy[v].fi, tm - tl, lazy[v].se);


        lazy[2*v + 2].fi = updateOp(lazy[2*v + 2].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 2].se == -1) lazy[2*v + 2].se = lazy[v].se;
        else lazy[2*v + 2].se = min(1, lazy[2*v + 2].se + lazy[v].se);

        tree[2*v + 2] = updateOp(tree[2*v + 2], lazy[v].fi, tm - tl, lazy[v].se);
        lazy[v] = {neutro, -1};
    }
*/

class segTree {
private:
    int size;
    vector<ll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    // Para query suma y update assign
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return b * len;
    }
    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    // Para query suma y update suma
    // ll updateOp(ll a, ll b, ll len){
    //     if(b == neutro) return a;
    //     if(a == neutro) return b*len;
    //     return a + b*len;
    // }
    // ll calcOp(ll a, ll b){
    //     if(a == neutro) return b;
    //     if(b == neutro) return a;
    //     return a + b;
    // }

    // Para query minimo y update suma
    // ll updateOp(ll a, ll b, ll len){
    //     if(b == neutro) return a;
    //     if(a == neutro) return b;
    //     return a + b;
    // }
    // ll calcOp(ll a, ll b){
    //     if(a == neutro) return b;
    //     if(b == neutro) return a;
    //     return min(a, b);
    // }

    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
        // Para Update de invertir (cambiar 0s por 1s y viceversa), usar:
        // lazy[2*v + 1] = !lazy[2*v + 1];
        // lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(lazy[2*v + 1], lazy[v], 1);
        applyUpdOp(tree[2*v + 1], lazy[v], tm - tl);
        applyUpdOp(lazy[2*v + 2], lazy[v], 1);
        applyUpdOp(tree[2*v + 2], lazy[v], tr - tm);
        lazy[v] = neutro;
    }

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

    // [l, r)
    ll calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    void build(vector<ll>& a, int v, int tl, int tr){ 
        if(tr == tl + 1){
            if(tl < sz(a)) tree[v] = a[tl];
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
        lazy.assign(2*size, neutro);
        tree.assign(2*size, 0LL);
    }

    void update(int l, int r, ll val){
        update(l, r, val, 0, 0, size);
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void build(vector<ll>& a){
        build(a, 0, 0, size);
    }
};

void solver(){
    int n, m; cin>>n>>m;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    segTree st; st.init(n);
    st.build(a);
    
    // Updates
    int l, r; ll val; cin>>l>>r>>val;
    st.update(l, r, val);

    // Calcular
    int l, r; cin>>l>>r;
    cout<<st.calc(l, r)<<endl;
}