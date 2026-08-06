#include "../../template.h"

/*
Segment Tree Lazy Propagation (ejemplo con update assign y calc suma).
- Es necesario que se cumpla la propiedad asociativa tanto en las operaciones de update como calc.
- Es necesario que se cumpla que calcOp(updateOp(a, x), updateOp(b, x)) == updateOp(calcOp(a, b), x),
  es decir, que updateOp sea distributiva relativa a calcOp, ejemplo, update de multiplicacion, calc
  suma. En caso de que no se cumpla esa propiedad (update assign, calc suma o update suma, calc suma),
  se debe ajustar utilizando la longitud del rango en la operacion update. 
- Tambien se pueden hacer updates donde cada valor a_i se lleva al minimo entre x y a_i (o maximo) y
  hacer consultas de elementos.
*/ 

class segTree {
private:
    int size;
    vl lazy;
    vl tree;

    ll neutro = LLONG_MAX - 1;

    // Para query suma y update assign
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        return b * len;
    }
    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1) return;
        int tm = (tr + tl) / 2;
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

    void build(vl& a, int v, int tl, int tr){ 
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
        tree.assign(2*size, 0LL); // Change
    }
    void update(int l, int r, ll val){update(l, r, val, 0, 0, size);}
    ll calc(int l, int r){return calc(l, r, 0, 0, size);}
    void build(vl& a){build(a, 0, 0, size);}
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