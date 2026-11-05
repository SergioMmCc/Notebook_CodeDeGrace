#include "../template.h"

/* NO TESTED
- Halla los puntos de articulacion de un grafo no 
  dirigido.
- Los puntos de articulacion son aquellos nodos que si
  se eliminaran del grafo haria que este se divida en 
  2 o mas componentes.
- Tener en cuenta que si solo hay un nodo o dos, estos
  no se marcan como puntos de articulacion (ya que al
  eliminarlo el grafo tendria '0' componentes o 
  seguiria siendo de uno solo).
- Si hubieran varios componentes y se quisieran hallar
  los puntos de articulacion de cada componente, se 
  recorren todos los nodos y se tira un DFS desde los
  que no han sido visitados. Se cumple la regla de que
  si un componente solo tiene uno o dos nodos estos no
  se cuentan como puntos de articulacion.
- Complejidad: O(n+m).
- Ejemplo 1-index pero sirve para 0-index.
*/

const int maxn = 2e5 + 5;
vector<vi> graph(maxn);
vb vis(maxn), isAP(maxn);
vi low(maxn), dep(maxn);

void DFS(int u, int prev){
    vis[u] = 1;
    low[u] = dep[u];
    int children = 0;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(vis[v]){ // Back-edge
            low[u] = min(low[u], dep[v]);
            continue;
        }
        dep[v] = dep[u] + 1;
        DFS(v, u);
        low[u] = min(low[u], low[v]);
        children++;
        if(prev != -1 && low[v] >= dep[u]) isAP[u] = 1;
    }
    if(prev == -1 && children > 1) isAP[u] = 1; // Raiz
}

void solver(){
    int n, m; cin>>n>>m;
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1, -1);
    for1(i,n) if(isAP[i]) cout<<"Articulation point: "<<i<<endl;
}
