#include "../template.h"

/*
- Complejidad O(m*log(n)).
Aplicaciones:
- Sirve para grafos con pesos negativos siempre y cuando no haya ciclos 
  negativos, en ese caso usar Bellman-Ford. Pero si el grafo es grande, 
  es propenso a dar TLE.
- Hallar las 'k' menores distancias (usando 'k' caminos diferentes, que
  pueden compartir aristas entre si, y donde cada camino puede visitar 
  el mismo nodo varias veces). Complejidad O(m*k*log(n*k)):
  Se puede modificar el vector de distancias, haciendo que sea un vector
  de colas de mayor prioridad. Asi en cada nodo se almacenan las 'k' 
  distancias menores. Al sacar un par nodo 'u' peso 'w1' de la cola de 
  prioridad del dijkstra, se verifica si su peso mayor en su cola de 
  prioridad es menor que 'w1', y en caso de que si, se continua con la 
  siguiente iteracion. En caso de que no, para cada arista que va hacia 
  'v' con peso 'w2', se verifica si este aun no tiene 'k' elementos en 
  su cola de prioridad y agregamos 'w1' + 'w2' tanto en su cola de 
  prioridad como en la del dijkstra. En caso de que si tenga 'k' 
  elementos, se revisa si 'w1' + 'w2' es menor que el valor mayor de la 
  cola de prioridad de 'v', en caso de que si, se saca el valor mayor 
  de la cola de prioridad de 'v' y se pone 'w1' + 'w2' tanto en la cola
  de prioridad de 'v' como en la del dijkstra.
- Potencial de un grafo (existe si y solo si no hay ciclos negativos):
  Si el grafo tiene pesos negativos, se halla una funcion p tal que para
  cada arista u->v, w(u->v) + p[u] - p[v] >= 0. (Si el grafo no tiene 
  pesos negativos, p[i] = 0 para todo nodo 'i'):
  Se halla creando un nuevo vertice 's' y aristas que vayan desde 's' a 
  todos los vertices del grafo con peso 0. Entonces se corre dijkstra 
  desde 's' y su distancia hacia cada vertice sera el valor de la 
  funcion p (todos estos seran <= 0 ya que hay una arista con pesos 0 
  desde 's' hacia todos los nodos). Ahora se reemplaza el peso 'w' de 
  cada arista u->v por 'w' + p[u] - p[v]. 
  Para saber la distancia desde 'u' hasta 'v' (la distancia real, que 
  habria usando los pesos del grafo original) se corre el dijkstra desde 
  'u' y la respuesta es d[v] - p[u] + p[v]
  Se puede usar para mejorar la complejidad del dijkstra cuando el grafo
  tiene pesos negativos si nos dan una funcion potencial valida de 
  antemano o alguna forma de calcularla sin correr el dijkstra.
*/

typedef pair<ll, int> pli;
const int maxn = 1e5 + 1;
const ll inf = 1e15;
vector<vector<pli>> graph(maxn);

void dijkstra(int s, vl& dis, vi& pa){  
    dis[s] = 0;
    pqueue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().se; ll w1 = pq.top().fi; pq.pop();
        if(dis[u] < w1) continue;
        for(pli &e : graph[u]){
            int v = e.se; ll w2 = e.fi;
            if(dis[v] > w1 + w2){
                dis[v] = w1 + w2;
                pa[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
}

void solver(){
    int n, m, s; cin>>n>>m>>s;
    for(int i = 0; i < m; i++){
        int u, v; ll w; cin>>u>>v>>w;
        graph[u].pb({w, v});
        graph[v].pb({w, u});
    }
    vl dis(n+1, INFL);
    vi pa(n+1, -1);
    dijkstra(s, dis, pa);
    for1(i,n) cout<<"vertex: "<<i<<" distancia: "<<dis[i]<<" padre: "<<pa[i]<<endl;
}