#include "../template.h"

/*
- Un Vertex Cover es un subconjunto de vértices C⊆V tal
  que cada arista del grafo tiene al menos un extremo en C.
  Un minimum vertex cover es el conjunto C de menor tamaño
  que cumple dicha condicion.
- Complejidad: en un grafo cualquiera es NP, pero para 
  arboles, la complejidad es O(n).
*/

const int maxn = 2e5 + 1;
vector<vi> tree(maxn);
int dp[maxn][2];

void DFS(int u, int pa){
    // dp[u][1] guarda el minimo si u en el cover, 0 si no esta
    dp[u][0] = 0; dp[u][1] = 1;
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(v, u);
    }

    // Si u esta en el cover, sus hijos pueden estar o no.
    // Si u no esta en el cover, todos sus hijos tienen que estar
    for(int v : tree[u]){
        if(v == pa) continue;
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(1, -1); // Da igual la raiz del arbol
    cout<<min(dp[1][0], dp[1][1])<<endl;
}