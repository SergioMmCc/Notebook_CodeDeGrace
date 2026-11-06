#include "../template.h"

/*
- Construye el arbol de modo que cada nodo esta lo mas cerca posible
  de la raiz, mediante BFS. Desde este arbol se hacen querys de LCA.
- Sirve para 1-index y 0-index.
- Sirve para grafos no dirigidos y dirigidos.
*/

const int maxn = 2e5 + 1;
const int LOG = 19; // El logaritmo base 2 del numero maximo de nodos
vector<vi> graph(maxn), up(maxn, vi(LOG));
vi dep(maxn, -1);

void BFS(int s){ // O(m + nlog(n))
    dep[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(dep[v] != -1) continue;
            dep[v] = dep[u] + 1;
            up[v][0] = u;
            for1(j,LOG-1) up[v][j] = up[up[v][j-1]][j-1];
            q.push(v);
        }
    }
}

int LCA(int a, int b){ // log(n)
    if(dep[a] < dep[b]) swap(a, b);
    int k = dep[a] - dep[b];
    forn0(j,LOG) if(k & (1 << j)) a = up[a][j]; // Pone a y b al mismo nivel
    if(a == b) return a;
    forn0(j,LOG){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solver(){
    // Construir
    int n, m, root; cin>>n>>m>>root;
    for0(i,m){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    BFS(root);

    cout<<LCA(u, v)<<endl; // Query
}