#include "../template.h"

/*
- BFS para grafo donde todas las aristas tienen peso 0 o w (w > 0).
- Complejidad: O(n + m).
- Se asume que el peso de las aristas no se da como parte de la 
  entrada sino que se puede hallar facilmente con una condicion 
  segun sean u y v. En caso de que el peso se de en la entrada es 
  mejor guardar el grafo como listas de pares.
*/

const int maxn = 1e5 + 1;
vi dis(maxn, INF);
vector<vi> graph(maxn);

void BFS(int s){
    dis[s] = 0;
    deque<int> q; q.push_front(s);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int v : graph[u]){
            int add = 0;
            if(condicion) add++;
            if(dis[v] > dis[u] + add){
                dis[v] = dis[u] + add;
                if(!add) q.push_front(v);
                else q.pb(v);
            }
        }
    }
}