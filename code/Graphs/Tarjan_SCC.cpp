#include "../template.h"

/* 
- Tarjan’s algorithm for finding strongly connected components.
- Complejidad: O(E + V).
- Los ids del SCC se guardan en 0-index.
- d[i] = Discovery time of node i. (Initialize to -1)
- low[i] = Lowest discovery time reachable from node
    i. (Doesn’t need to be initialized)
- scc[i] = Strongly connected component of node i. (Doesn’t
    need to be initialized) (0-index)
- s = Stack used by the algorithm (Initialize to an empty
    stack)
- stacked[i] = True if i was pushed into s. (Initialize to
    false)
- ticks = Clock used for discovery times (Initialize to 0)
- current_scc = ID of the current_scc being discovered
    (Initialize to 0)

Propiedades
- Al comprimir cada SCC como un nodo individual, se obtiene un DAG.
- Si de un SCC A hay un camino a otro SCC B, no hay camino de B hacia A.
- Si se invierten todas las aristas, los SCC no cambian.
Aplicacion 2-SAT:
- Dada una expresion booleana en CNF (Conjuctive Normal Form), lo cual 
  es una conjucion de multiples clausulas, donde cada clausula tiene
  exactamente 2 literales, ej: (a v b) ^ (c v d) ^ ... . Se debe hallar 
  un valor para cada variable (True o False) tal que la formula sea True.
  Para resolverlo se crean 2 nodos para cada literal (a y ~a), y para
  cada clausula (a v b) se crean 2 aristas: '~a'->'b' y '~b'->'a'. Se 
  corre Tarjan para hallar los SCC, si hay algun literal 'a' tal que los
  nodos 'a' y '~a' hacen parte del mismo SCC, no hay solucion. De lo 
  contrario si la hay y para hallar una asignacion valida se comprime el 
  grafo original y se realiza un toposort, si en el orden del toposort el 
  SCC de 'a' se encuentra antes que el SCC de '~a', entonces 'a' es False, 
  de lo contrario es True.
*/

void tarjan(int u, vector<vi>& graph, vi&d, vi& low, vi& scc, vi& reps, vb& stacked, stack<int>& s, int& ticks, int& current_scc){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = 1;
    const vi &out = graph[u];
    for(int k=0, m=sz(out); k<m; ++k){
        const int &v = out[k];
        if(d[v] == -1){
            tarjan(v, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
            low[u] = min(low[u], low[v]);
        }
        else if(stacked[v]) low[u] = min(low[u], low[v]);
    }
    if(d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] = 0;
            scc[v] = current_scc;
        }while (u != v);
        current_scc++;
    }
}

void solver(){
    int n, m; cin>>n>>m;

    vector<vi> graph(n+1);
    vi d(n+1, -1), low(n+1), scc(n+1), reps(n+1, 0);
    vb stacked(n+1);
    stack<int> s;
    int ticks = 0, current_scc = 0;

    for1(i,m){
        int u, v;cin>>u>>v;
        graph[u].pb(v);
    }

    // Hallar los SCC
    for(int i = 1; i <= n; i++){ // 1-index, se puede cambiar a 0-index
        if(d[i] == -1) 
            tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
    }

    cout<<current_scc<<endl; // Cantidad de SCC del grafo

    // Armar grafo comprimido (O(V + E))
    vector<vi> graph2(current_scc+1);
    vi inDegree(current_scc+1);
    for1(i,n){
        for(int v : graph[i]){
            if(scc[v] != scc[i]){ // Verificar que la arista vaya a otro SCC
                graph2[scc[i]+1].pb(scc[v]+1);
                inDegree[scc[v]+1]++;
            }
        }
    }
}