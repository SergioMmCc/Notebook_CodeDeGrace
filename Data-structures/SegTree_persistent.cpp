#include "../template.h"

/*
- 0-index. Implementacion de sumas.
- Los nodos se relacionan entre versiones usando los indices, es por
  eso que build y update retornan indices.
- Tener cuidado con los casos donde se retorna neutro, agregar un if.
- Cada update crea una nueva version.
- Puede ser util guardar un mapa que diga la version a la que 
  corresponde cada update si para el ejercicio no necesariamente
  cada update representa una version nueva. En este caso tener
  cuidado porque cada update se hace sobre una nueva version y 
  puede ser necesario actualizar tambien el mapa.
- Se usan las funciones between para hacer calculos entre versiones,
  en esta implementacion se hacen calculos de suma en v1 - suma en v2.
  Esto se puede usar para cualquier tipo de calculo que tenga inversa.
- Pude ser util construir el array mediante updates, ya que en 
  ocasiones se requiere hacer las queries usando l y r como v1 y v2.

Aplicaciones tipicas:
- Cantidad de distintos en un rango (no updates):
  Para hallarlo se recorre el array original con i entre 1 y n, sobre
  la ultima version se hace una update poniendo en la posicion i un 
  valor de 1, y se revisa la ultima vez j que el valor a[i] aparecio
  en el array, y se hace una update en la ultima version podiendo
  en la posicion j un valor de 0.
  Para las queries l, r se hace el calculo en la version r del array
  (usar un mapa para manejar las versiones adecuadamente), en el rango
  [l, r], el valor de esa query es el numero de elementos distintos
  en ese segmento.
- kth elemento menor en un rango (no updates):
  De manera similar, se recorre el array original con i entre 0 y n-1,
  sobre la ultima version se hace un update agregando 1 a la posicion 
  a[i]. Para las queries se toman l, r como las versiones del segtree
  y se hacen las queries entre 0 y n. Dentro de calcBetween se usa una
  tecnica similar a la del kth one, donde se mira si en el hijo left
  la resta entre versiones es > k y se va hacia ese hijo o de lo 
  contrario se va hacia el hijo derecho, hasta que finalmente el tamaño
  del rango sea == 1 y se retorna tl.
*/

struct node{
    ll val; int l, r; // Change
};

const int LEN = 1e7; // tope de nodos totales (usar aprox 4*n + (q+5)*(log(n) + 5))

class segTree {
private:
    node neutro = {LLONG_MAX - 1, -1, -1}; // Change

    node calcOp(node a, node b){ // Change
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        node ans = {a.val + b.val, -1, -1}; // Change
        return ans;
    }

    node calcDifBetween(node v1, node v2){
        if(v1.val == neutro.val) return neutro;
        return {v2.val - v1.val, -1, -1}; // Change
    }

    node calcSolapeBetween(node a, node b){
        if(a.val == neutro.val) return b;
        if(b.val == neutro.val) return a;
        return {a.val + b.val, -1, -1};  // Change
    }

    vector<node> tree;
    int n, idx = 0;

    int update(int prv, int pos, ll val, int tl, int tr){
        int v = idx++;
        tree[v] = tree[prv];
        if(tr - tl == 1){
            tree[v].val = val; // Change
            return v;
        }
        int tm = (tl + tr) / 2;
        if(pos < tm) tree[v].l = update(tree[v].l, pos, val, tl, tm);
        else tree[v].r = update(tree[v].r, pos, val, tm, tr);
        node combined = calcOp(tree[tree[v].l], tree[tree[v].r]);
        tree[v].val = combined.val;
        return v;
    }

    // [l, r)
    node calc(int v, int l, int r, int tl, int tr){ // Change si walking on segment tree
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v]; // si walking -> tr - tl == 1

        int tm = (tl + tr) / 2;
        node m1 = calc(tree[v].l, l, r, tl, tm);
        node m2 = calc(tree[v].r, l, r, tm, tr);
        return calcOp(m1, m2);
    }

    // [l, r) y [v1, v2]
    node calcBetween(int v1, int v2, int l, int r, int tl, int tr){ // Change si walking on segment tree
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return calcDifBetween(tree[v1], tree[v2]); // si walking -> tr - tl == 1
        int tm = (tl + tr) / 2;
        node lc = calcBetween(tree[v1].l, tree[v2].l, l, r, tl, tm);
        node rc = calcBetween(tree[v1].r, tree[v2].r, l, r, tm, tr);
        return calcSolapeBetween(lc, rc);
    }

    int build(int tl, int tr, vl& a){
        int v = idx++;
        if(tr - tl == 1){
            if(tl < sz(a)) tree[v] = {a[tl], -1, -1}; // Change
            return v;
        }
        int tm = (tl + tr) / 2;
        int l = build(tl, tm, a), r = build(tm, tr, a);
        node combined = calcOp(tree[l], tree[r]);
        tree[v] = {combined.val, l, r};
        return v;
    }

public:
    vi roots; // roots[i] = índice de la raíz de la versión i

    void init(int n_){
        n = n_;
        idx = 0;
        tree.assign(LEN, neutro); // Cuidado si se debe inicializar en 0 o similar
        roots.clear();
    }

    // Crea una nueva version a partir de "ver" (indice en roots)
    void update(int ver, int pos, ll val){
        roots.pb(update(roots[ver], pos, val, 0, n));
    }

    // Calculo sobre la version "ver"
    node calc(int ver, int l, int r){
        return calc(roots[ver], l, r, 0, n);
    }

    // Para hacer calculos entre versiones
    node calcBetween(int v1, int v2, int l, int r){
        return calcBetween(roots[v1], roots[v2], l, r, 0, n);
    }

    // Crea la version 0 a partir del arreglo inicial
    void build(vl& a){
        roots.pb(build(0, sz(a), a));
    }
};

void solver(){
    int n; cin>>n;
    vl a(n);
    for0(i,n) cin>>a[i];

    // Inicializar
    segTree st; 
    st.init(n);
    st.build(a);

    // Updates
    int ver, idx; ll val; cin>>ver>>idx>>val;
    st.update(ver, idx, val);

    // Calc
    int ver, l, r; cin>>ver>>l>>r;
    cout<<st.calc(ver, l, r).val<<endl;

    // Calc between
    int v1, v2, l, r; cin>>v1>>v2>>l>>r;
    cout<<st.calcBetween(v1, v2, l, r).val<<endl;

    // Copy any version
    int ver; cin>>ver;
    st.roots.pb(st.roots[ver]);

    // Valor de la ultima version
    int lastV = sz(st.roots) - 1;
}