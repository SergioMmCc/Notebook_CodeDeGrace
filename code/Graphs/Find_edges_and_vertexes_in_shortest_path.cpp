#include "../template.h"

/*  
- Aristas que pueden ser parte de un camino mas corto desde 's' a 't'
  (si hay pesos negativos, no deben haber ciclos negativos entre 's' y 
  't'):
  Se corre BFS, Dijkstra o SPFA desde s y desde t (si el grafo es 
  dirigido toca crear un grafo invertido para el dijkstra desde t), 
  despues se recorre cada arista u->v y si la distancia de 's' a 'u', 
  mas la distancia de 't' a 'v' mas el peso de esa arista es igual a 
  la distancia de 's' a 't', en caso de que si, esa arista puede hacer 
  parte de un camino mas corto de 's' a 't'.
  Si el grafo solo tiene pesos positivos, se puede armar un grafo con 
  estas aristas se obtiene un DAG.
- Hallar las aristas y/o vertices por los cuales es obligatorio pasar
  para llegar de 's' a 't' de la manera mas eficiente posible (grafo no 
  ponderado):
  Para los nodos: solo se toman en cuenta aquellos nodos 'u' donde
  dis1[u] + disn[u] == dis1[n] y se forman capas. Cada nodo 'v' hace parte
  de la capa dis1[v]. Entonces se revisa capa por capa y en aquellas que 
  solo haya un nodo se dice que dichos nodos son obligatorios.
  Para las aristas es similar: se toman en cuenta solo aquellas aristas
  u->v donde dis1[u] + 1 + disn[v] == dis1[n]. Cada arista u->v hace parte
  de la capa dis1[u]. Se revisa capa por capa y en aquellas que solo haya
  una arista se dice que dichas aristas son obligatorias.
- Hallar las aristas y/o vertices por las cuales es obligatorio pasar para 
  llegar de 's' a 't' de la manera mas corta posible (pesos estrictamente 
  positivos) (tener cuidado en caso de que no se pueda llegar de 's' a 't'):
  Para las aristas:
  * Complejidad: O(n+m) del BFS mas la complejidad de armar el dag.
  * En el grafo original tambien se debe guardar el indice de las aristas.
  * Se arma el dag con las aristas que pueden estar en algun camino mas 
    corto de 's' a 't'.
  * Se corre la funcion "findObligatory"
  Para los nodos: todos aquellos que hagan parte de alguna arista 
  obligatoria se consideran obligatorios.
*/

typedef pair<ll, pii> plii;
const int maxn = 1e5 + 1;
vector<vector<plii>> graph(maxn);
vector<vii> dag(maxn);

void findObligatory(int s, int t, int n, vb& ans, vi& inDegree){
    vb vis(n+1); vis[s] = 1;
    queue<int> q; q.push(s);
    int roads = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u != t) roads += sz(dag[u]) - 1; // Aumentamos roads con el numero de salidas de u-1
        for(pii &e : dag[u]){
            int v = e.fi, idx = e.se;
            if(roads == 1) ans[idx] = 1; // Esa arista esta en todos los caminos

            if(vis[v]) roads--; // Si ya habia visitado v antes, disminuyo roads
            vis[v] = 1;
            inDegree[v]--; // Resto su número de aristas de entrada
            if(!inDegree[v]) q.push(v); // Al visitar la ultima arista que va a 'v', entra en la cola
        }
    }
}

void solver(){
    int n, m, s, t; cin>>n>>m>>s>>t;
    for0(i,m){
        int u, v; ll w; cin>>u>>v>>w; // Ejemplo grafo con pesos
        graph[u].pb({w, {v, i}}); // Si es grafo dirigido, ponerlas tambien en el grafo inverso
        graph[v].pb({w, {u, i}});
    }

    // Se debe correr BFS, Dijsktra o SPFA para hallar ds (distancias desde s) y dt (distancias desde t)
    vl ds(n+1, INFL), dt(n+1, INFL);

    // Hallar las aristas que estan en algun camino mas corto de 's' a 't'
    vi inDegree(n+1); // Cantidad de aristas que llegan a cada nodo en el dag
    for1(i,n){
        for(plii &e : graph[i]){
            int v = e.se.fi, idx = e.se.se; ll w = e.fi;
            if(ds[i] + dt[v] + w == ds[t]){ // Esta arista puede estar (y en esa direccion)
                dag[i].pb({v, idx}); // Si todos los pesos son positivos, armar el dag
                inDegree[v]++;
            }
        }
    }

    // Hallar aristas obligatorias, solo si todos los pesos son positivos
    vb ans(m);
    findObligatory(s, t, n, ans, inDegree);
    for0(i,m) if(ans[i]) cout<<"La arista con indice "<<i<<" es obligatoria"<<endl;
}