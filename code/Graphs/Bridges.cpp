#include "../template.h"

/*
// O(n + m)
- Halla las aristas bridge en un grafo no dirigido conexo.
- Tener en cuenta que si el grafo no es conexo y se quieren hallar puentes
  en algun componente, tocaria lanzar un DFS para cada componente y en el
  for del final saltarse todos los vertices desde los cuales se lanzo algun
  DFS.
- No toma en cuenta aristas multiples.
- Para hallar los two edge connected components, simplemente 
  eliminar los bridges del grafo y hallar los componentes con
  normalidad.
*/

const int maxn = 2e5 + 5;
vector<vi> graph(maxn);
vb vis(maxn);
vi dp(maxn), sons[maxn], father(maxn), dep(maxn);

void DFS(int u, int prev){
    vis[u] = 1;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(vis[v]){ // Back-edge
            // Revisar que la arista vaya de abajo hacia arriba
            // para no considerarla 2 veces
            if(dep[v] > dep[u]) continue;
            dp[u]++;
            dp[v]--;
            continue;
        }
        sons[u].pb(v); // Span-edge
        father[v] = u;
        dep[v] = dep[u] + 1;
        DFS(v, u);
    }
}

int calc(int u){
    for(int v : sons[u]) dp[u] += calc(v);
    return dp[u];
}

void solver(){
    // Construir
    int n, m; cin>>n>>m;
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb(v); // Las aristas TIENEN que estar en ambas listas de adyacencia
        graph[v].pb(u);
    }

    // Da igual cual sea la raiz asi que se usa root = 1
    DFS(1 /*root*/, -1); // Crear DFS tree
    calc(1 /*root*/); // Calcular el dp

    forlr(i,2,n){
        // Si dp[i] == 0, la arista que conecta i y su padre son un puente
        if(!dp[i]) cout<<"Bridge: "<<father[i]<<" - "<<i<<endl;
    }
}