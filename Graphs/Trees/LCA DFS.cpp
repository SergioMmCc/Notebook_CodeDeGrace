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

/*
    LCA usando Euler Tour Technique.
    Consiste en utilizar un DFS para marcar la primera vez que se visita cada nodo (start), su profundidad
    (depth) y tener un array (id) en el que se inserta un valor u cada que dicho nodo es visitado en el DFS, 
    es decir, cuando se visita por primera vez y cuando se termina de visitar un hijo, lo cual nos dice que 
    cada nodo sera agregado 1 vez por cada hijo que tiene mas una por si mismo, por tanto el array id tendra
    2*n - 1 elementos.
    Para hacer las queries de LCA(u, v) se necesita hallar el nodo con menor profundidad en el intervalo
    [start[u], start[v]], con start[u] <= start[v], lo cual se hara con una sparse table de minimos. La 
    sparse table se rellenara con los pares {depth[id[i]], id[i]}, para 0 <= i < sz(id). Cada query halla
    el nodo con menor profundidad en ese intervalo en O(1).

    Para hallar la distancia entre 2 nodos del arbol se puede usar la siguiente formula:
    distancia(u, v) = depth[u] + depth[v] - 2*depth[LCA(u, v)]
*/

const int maxn = 2e5 + 1;
vector<vector<int>> tree(maxn);
vector<int> id, depth(maxn), start(maxn);
vector<vector<pii>> rmq;

// Llenar sparse table
// O(nlg(n))
void fillRMQ(){
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
void DFS(int u, int pa){
    start[u] = sz(id); // Marcar en que momento se visito por primera vez
    id.pb(u); // Insertar cuando se visita el nodo pro primera vez
    for(int v : tree[u]){
        if(v == pa) continue;
        depth[v] = depth[u] + 1;
        DFS(v, u);
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
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v; u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(0, -1);
    fillRMQ();

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++)
            cout<<"El Lowest Common Ancestor entre "<<i<<" y "<<j<<" es: "<<LCA(i, j)<<endl;
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