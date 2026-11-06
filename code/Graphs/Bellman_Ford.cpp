#include "../template.h"

/*
- Para grafos dirigidos que pueden tener aristas de peso negativo.
- Complejidad O(n * m)
- Si hay un ciclo de peso negativo alcanzable desde s retorna 0. Si
  no, retorna 1 y la minima distancia desde s hacia cualquier nodo.
- Para saber si hay algun ciclo negativo no necesariamente alcanzable 
  desde un vertice s, se inicializan todas las distancias en 0 y el 
  proceso es el mismo: se hacen n-1 rondas y despues una extra donde
  si hay una mejora quiere decir que si hay ciclos negativos.
- Si queremos saber el camino de algun ciclo negativo (sabiendo que 
  hay alguno), se debe tambien calcular el padre de cada nodo (si
  hay mejoria desde a hacia b, se dice que a es el padre de b). En el 
  Bellman Ford retornamos algun vertice que en la ultima ronda haya 
  reducido su distancia, luego viajamos hacia su padre n veces (ya que 
  puede ser que el vertice que sufrio una reduccion no este dentro del 
  ciclo sino despues de uno) y decimos que ese nodo al que se llega es
  'v'. Despues se va viajando desde 'v' yendo a sus antecesores hasta 
  que volvamos a llegar a 'v' y finalmente se invierte ese recorrido.
- Para saber si hay un ciclo negativo en algun camino desde s hasta t, 
  se corre el Bellman-Ford, se marcan los vertices para los cuales hay 
  una mejora en la n-esima ronda y se corre un BFS con t como source, 
  invirtiendo las aristas del grafo. Si algun vertice marcado es 
  alcanzable desde t, quiere decir que si hay ciclos negativos en el 
  camino desde s hasta t.
*/

struct Edge{
    int u, v; ll w;
};

bool bellmanFord(int s, int n, vector<Edge>& edges, vl& dis){
    dis[s] = 0;
    for1(i,n){ // Se hace un maximo de n-1 rondas
        bool cond = 0;
        for(Edge &e : edges){
            int u = e.u, v = e.v; ll w = e.w;
            if(dis[u] < INFL && dis[v] > dis[u] + w){ 
                if(i == n) return 0; // Hay ciclos de peso negativo
                dis[v] = dis[u] + w;
                cond = 1; // Marcamos que en esta ronda hubo al menos una mejora
            }
        }

        if(!cond) return 1;
    }

    return 1;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<Edge> edges;
    for0(i,m){
        int u, v; ll w; cin>>u>>v>>w;
        edges.pb({u, v, w});
    }

    vl dis(n+1, INFL);
    bool cond = bellmanFord(source, n, edges, dis);
}