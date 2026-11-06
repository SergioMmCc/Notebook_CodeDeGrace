#include "../template.h"

/*
- Complejidad O(n * m) 
- Retorna 0 si hay ciclos negativos. Si no, retorna 1 y halla la
  minima distancia desde s hacia cualquiuer nodo.
- Misma complejidad que Bellman-Ford, pero mejor en la practica.
- mcfx optimization:
  Tambien corre en O(n * m), pero suele ser mas rapido en la
  practica teniendo en cuenta:
  * Suele funcionar muy bien en grid graphs (grafos tipo cuadro).
  * No funciona bien en grafos estrella.
  Consiste en usar una deque en lugar de una queue. Antes de agregar 
  cada vertice se revisa si este se ha procesado entre 2 y sqrt(n) 
  veces, en cuyo caso de pone al frente de la deque. De lo contrario
  se pone al final de la deque.
*/

typedef pair<ll, int> pli;
const int maxn = 1e4 + 1;
vector<vector<pli>> graph(maxn);

// Implementacion normal:
bool spfa(int s, int n, vl& dis){
    dis[s] = 0;
    vi count(n+1);
    vb in(n+1); in[s] = 1;
    queue<int> q; q.push(s);
 
    while(!q.empty()){
        int u = q.front(); q.pop();
        in[u] = 0; // Marca que el vertice ya no esta en la cola
 
        for(pli edge : graph[u]){
            int v = edge.se; ll w = edge.fi;
            
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!in[v]){ // Antes de meter un vertice a la cola, revisa que no se este ya
                    in[v] = 1; // Marca que el vertice ahora esta en la cola
                    q.push(v);
                    count[v]++;
                    if(count[v] > n) return 0; // Si se ha metido a la cola mas de n veces -> ciclo negativo
                }
            }
        }
    }
 
    return 1; // No hay ciclos negativos
}

void solver(){
    int n, m; cin>>n>>m;
    for0(i,m){
        int u, v; ll w; cin>>u>>v>>w;
        graph[u].pb({w, v});
    }

    vl dis(n+1, INFL);
    bool cond = spfa(source, n, dis);
}