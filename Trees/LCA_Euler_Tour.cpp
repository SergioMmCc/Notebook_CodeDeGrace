#include "../template.h"

/*
LCA usando Euler Tour Technique.
- Consiste en utilizar un DFS para marcar la primera vez que se 
  visita cada nodo (start), su profundidad (depth) y tener un 
  array (id) en el que se inserta un valor u cada que dicho nodo 
  es visitado en el DFS, es decir, cuando se visita por primera 
  vez y cuando se termina de visitar un hijo, lo cual nos dice 
  que cada nodo sera agregado 1 vez por cada hijo que tiene mas 
  una por si mismo, por tanto el array id tendra 2*n - 1 elementos.
- Para hacer las queries de LCA(u, v) se necesita hallar el nodo 
  con menor profundidad en el intervalo [start[u], start[v]], 
  con start[u] <= start[v], lo cual se hara con una sparse table 
  de minimos. La sparse table se rellenara con los pares 
  {depth[id[i]], id[i]}, para 0 <= i < sz(id). Cada query halla el 
  nodo con menor profundidad en ese intervalo en O(1).
- Para hallar la distancia entre 2 nodos del arbol se puede usar 
  la siguiente formula: 
  distancia(u, v) = depth[u] + depth[v] - 2*depth[LCA(u, v)]
*/

const int maxn = 2e5 + 1;
vector<vi> tree(maxn);
vi id, depth(maxn), start(maxn);

// Halla los valores correspondientes de los arrays depth, id y start
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

// Halla el LCA entre 2 nodos
// O(1)
int LCA(int a, int b){
    if(start[a] > start[b]) swap(a, b); // Se asegura que start[a] corresponda a l y start[b] a r
    return query(start[a], start[b]).se; // Query a la sparse table
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

    
    // Hallar LCA
    cout<<LCA(u,v)<<endl;
}