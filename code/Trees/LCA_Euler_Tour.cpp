#include "../template.h"

/*
LCA usando Euler Tour Technique.
- La sparse table se rellenara con los pares 
  {depth[id[i]], id[i]}, para 0 <= i < sz(id).
- Para hacer las queries de LCA(u, v) se necesita hallar el nodo 
  con menor profundidad en el intervalo [start[u], start[v]], 
  con start[u] <= start[v], lo cual se hara con una sparse table 
  de minimos. Cada query halla el nodo con menor profundidad en 
  ese intervalo en O(1).
- Para hallar la distancia entre 2 nodos u,v del arbol:
  distancia(u, v) = depth[u] + depth[v] - 2*depth[LCA(u, v)]
*/

// AGREGAR SPARSE TABLE DE PARES Y MINIMOS

const int maxn = 2e5 + 1;
vector<vi> tree(maxn);
vi id, depth(maxn), start(maxn);

// Llenar los arrays depth, id y start
void DFS(int u, int pa){
    start[u] = sz(id); // Marcar en que momento se visito por primera vez
    id.pb(u); // Insertar cuando se visita el nodo por primera vez
    for(int v : tree[u]){
        if(v == pa) continue;
        depth[v] = depth[u] + 1;
        DFS(v, u);
        id.pb(u); // Insertar cada vez que se regresa al nodo
    }
}

// O(1)
int LCA(int a, int b, rmq& st){
    if(start[a] > start[b]) swap(a, b); // Asegura que start[a] sea l y start[b] sea r
    return st.calc(start[a], start[b]).se; // Query a la sparse table
}

void solver(){
    int n; cin>>n;
    for1(i,n-1){
        int u, v; cin>>u>>v; u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    // Precalcular depth e id
    DFS(0, -1);

    // Llamar sparse table
    vii a;
    for0(i,sz(id)) a.pb({depth[id[i]], id[i]});
    rmq st; st.build(a);
    
    // Hallar LCA
    cout<<LCA(u, v, st)<<endl;
}