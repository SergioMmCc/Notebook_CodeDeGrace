#include "../template.h"

// Hallar el Minimum Spanning Tree de un grafo no dirigido y conexo
// Complejidad O(m * lg(n))

const int maxn = 1e5 + 1;
typedef pair<ll, int> pli;
vector<vector<pli>> graph(maxn);

void prim(int s, int n, vl& dis, vi& pa){
    vb inQueue(n+1, 1); 
    dis[s] = 0;
    pqueue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(!inQueue[u]) continue;
        inQueue[u] = 0;
        for(pli &edge : graph[u]){
            int v = edge.se; ll w = edge.fi;
            if(inQueue[v] && dis[v] > w){
                dis[v] = w;
                pa[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
}

void solver(){
    // Construir
    int n, m, source; cin>>n>>m>>source;
    for0(i,m){
        int u, v; ll w; cin>>u>>v>>w;
        graph[u].pb({w, v});
        graph[v].pb({w, u});
    }
    vl dis(n+1, INFL); // Distancia de cada nodo a su padre en el MST
    vi pa(n+1, -1); // Padre de cada nodo en el MST

    // Calcular
    prim(source, n, dis, pa);
    
    // Peso total del MST
    ll totalWeight = 0;
    for(int i = 1; i <= n; i++) totalWeight += dis[i];
    cout<<totalWeight<<endl;
}