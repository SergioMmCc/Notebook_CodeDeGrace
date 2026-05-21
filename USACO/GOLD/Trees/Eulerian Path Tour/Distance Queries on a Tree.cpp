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
typedef pair<pii, ll> piil;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<piil> viil;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class segTree {
private:
    int size;
    vector<ll> lazy;
    vector<ll> tree;

    ll neutro = LLONG_MAX - 1;

    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b*len;
        return a + b*len;
    }

    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }

    void applyUpdOp(ll &a, ll b, ll len){
        a = updateOp(a, b, len);
    }

    // O(1)
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
    ll calc(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return neutro;
        if(tl >= l && tr <= r) return tree[v];

        int tm = (tl + tr) / 2;
        ll m1 = calc(l, r, 2*v + 1, tl, tm);
        ll m2 = calc(l, r, 2*v + 2, tm, tr);
        return calcOp(m1, m2);
    }

    // O(n)
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

const int maxn = 2e5 + 1;
vector<vector<int>> tree(maxn);

void DFS(vector<pii>& ran, vi& depth, int u, int pa, int &cnt){
    // Se dice que el rango de u inicia en cnt. Ademas ese sera su indice en el array que se contruira.
    ran[u].fi = cnt;
    cnt++; // Se suma 1 para guardar que se ha visitado un nuevo nodo
    for(int v : tree[u]){
        if(v == pa) continue;
        depth[v] = depth[u] + 1;
        DFS(ran, depth, v, u, cnt); // Se visita el subarbol que tiene u como raiz
    }

    // Despues de visitar los nodos que pertenecen al subarbol de u, podemos decir en que indice termina el rango de u
    ran[u].se = cnt;
}

vector<int> id, start(maxn);
vector<vector<pii>> rmq;

// Llenar sparse table
// O(nlg(n))
void fillRMQ(vi& depth){
    int n = sz(id); rmq.resize(n);
    int lgn = 31 - __builtin_clz(n);

    for(int i = 0; i < n; i++){
        rmq[i].resize(lgn + 1);
        rmq[i][0] = {depth[id[i]], id[i]};
    }

    for(int j = 1; j <= lgn; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
}

// Halla el valor minimo en el intervalo [l, r]
// O(1)
pii query(int l, int r){
    int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
    return min(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]); // [l, r]
}

// Halla los valores correspondientes de los arrays depth, id y start
void DFS2(int u, int pa){
    start[u] = sz(id); // Marcar en que momento se visito por primera vez
    id.pb(u); // Insertar cuando se visita el nodo por primera vez
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS2(v, u);
        id.pb(u); // Insertar cada vez que se regresa al nodo
    }
}

// Halla el LCA entre 2 nodos
// O(1)
int LCA(int a, int b){
    if(start[a] > start[b]) swap(a, b); // Se asegura que start[a] corresponda a l y start[b] a r
    return query(start[a], start[b]).se;
}

void solver(){
    int n; cin>>n;
    viil edj(n-1);
    for(int i = 1; i < n; i++){
        int u, v; ll w; cin>>u>>v>>w;
        u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
        edj[i-1] = {{u, v}, w};
    }

    vii ran(n);
    vi depth(n);
    int cnt = 0;
    DFS(ran, depth, 0, -1, cnt);
    vi orden(n);
    for(int i = 0; i < n; i++) orden[ran[i].fi] = i;

    segTree st; st.init(n);
    for(int i = 0; i < n-1; i++){
        int u = edj[i].fi.fi, v = edj[i].fi.se; ll w = edj[i].se;
        if(depth[u] > depth[v]){
            swap(edj[i].fi.fi, edj[i].fi.se);
            swap(u, v);
        }

        st.update(ran[v].fi, ran[v].se, w);
    }

    DFS2(0, -1);
    fillRMQ(depth);

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int idx; ll w; cin>>idx>>w; 
            idx--;
            ll dif = w - edj[idx].se;
            int v = edj[idx].fi.se;
            st.update(ran[v].fi, ran[v].se, dif);
            edj[idx].se = w;
        }
        else{
            int u, v; cin>>u>>v;
            u--; v--;
            int aux = LCA(u, v);
            cout<<st.calc(ran[u].fi, ran[u].fi + 1) + st.calc(ran[v].fi, ran[v].fi + 1) - 2*st.calc(ran[aux].fi, ran[aux].fi + 1)<<endl;
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