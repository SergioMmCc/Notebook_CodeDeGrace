#include "../template.h"


/*
IMPORTAR EL DSU.
- Halla el peso del MST, asumiendo que el grafo es conexo (sirve
  perfectamente para grafos con pesos negativos).
- Complejidad O(m * log(m)) por el ordenamiento de las aristas.
- Como saber si una arista esta en ningun, alguno o todos los MST:
  * Para ambos, la complejidad sigue siendo O(m * log(m)).
  * Para decidir que aristas pueden hacer parte del MST: se procesan 
    las aristas por grupos del mismo peso. Para cada grupo nuevo 
    inicialmente se revisa cada arista, si los vertices que 
    conecta ya hacen parte del mismo componente entonces esa arista 
    no hace parte de ningun MST, en caso contrario si hace 
    parte de al menos un posible MST.
    Despues de hacer esa comprobacion para todas las aristas del 
    grupo, se agregan al DSU.
  * Para saber que aristas estan en todos los posibles MST: para 
    cada grupo se constuye un grafo (que puede ser disconexo) solo 
    con las aristas de este grupo que pueden ser parte de un MST y 
    con los representantes de cada nodo (los nodos padre). Se hallan 
    los puentes de dicho grafo. Estos puentes son aristas que estan 
    en todos los MST.
*/

struct edge {
    int u, v; ll w;
    bool operator<(const edge& that) const { // Ordenar las aristas por el menor peso
        return w < that.w; // Cambiar '<' por '>' para hallar el Maximal Spanning Tree
    }
};

ll kruskal(vector<edge>& edges, int n){
    ll total = 0;
    sort(all(edges));
    DSU uf(n+1);

    for0(i,sz(edges)){
        int u = edges[i].u, v = edges[i].v; ll w = edges[i].w;
        if(uf.join(u ,v)) total += w;
    }

    return total; // Retornar el peso total del MST
}

void solver(){
    int n, m; cin>>n>>m;
    vector<edge> edges;
    for0(i,m){
        int u, v; ll w; cin>>u>>v>>w;
        edge newEdge = {u, v, w};
        edges.pb(newEdge);
    }

    cout<<kruskal(edges, n)<<endl;
}