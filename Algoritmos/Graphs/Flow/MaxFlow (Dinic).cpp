#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

// Aplicado en grafos de flujo dirigidos con capacidades en las aristas
// Complejidad O(v^2 * E)
// Para grafos con capacidades unitarias o en redes densas O(sqrt(V) * E)

/* 
   Aplicaciones:
   - Maximo flujo
   - Minimo corte:
     Es lo mismo que el maximo flujo. El conjunto de nodos alcanzables (partiendo
	 desde source) sin pasar por aristas saturadas es un lado del corte (left), y 
	 los no alcanzables son el otro lado del corte (right). Las aristas que 
	 pertenecen al mincut son aquellas que van de left a right y estan saturadas.
   - Edge-disjoint paths:
     Para hallar el maximo de caminos desde source hasta sink sin repetir aristas,
	 se usa un flujo donde cada arista tiene capacidad 1. Para reconstruir estos
	 caminos podemos guardar para cada nodo u una cola con los nodos v a los que 
	 este envia flujo, entonces mientras la cola de source no este vacia, tomamos
	 el primer elemento v, nos movemos a la cola de v y sacamos el primer vertice x
	 al que este envia flujo y asi sucesivamente hasta que llegamos a sink.
   - Node-disjoint paths:
	 Se resuelve de la misma manera que Edge-disjoint paths pero dividiendo los 
	 nodos en uin (2*u) y uout (2*u + 1) y creando una arista con capacidad 1 
	 entre ellos. Si hay una arista entre u y v, conectamos uout con vin. 
   - Minimum vertex cut
	 Para hallar el minimum vertex cut tendriamos que llamar Dinic con 2*n + 2
	 y añadir una arista entre cada 2*i y 2*i + 1 con capacidad de 1, para
	 0 <= i < n. Despues se agregan aristas con capacidad 1 según las condiciones
	 del ejercicio o del grafo original. Si buscamos añadir una arista desde un
	 vertice u hasta un vertice v, usamos: graph.addEdge(2*u + 1, 2*v, 1).
	 Despues agregamos aristas desde el nodo 2*n hacia todos los nodos iniciales
	 y desde todos los nodos finales hacia el nodo 2*n + 1.
	 Finalmente, usamos graph.calc(2*n, 2*n + 1), para hallar el maximo flujo
	 desde 2*n (que cumple la funcion de source-fuente), hasta 2*n + 1 (que cumple
	 la funcion de sink-sumidero). El valor del maximo flujo corresponde al valor
	 del minimum vertex cut.
   - Node-disjoint path cover en un DAG:
     Un path cover es un conjunto de caminos en un grafo tal que cada nodo pertenece
	 a al menos un camino. Un Node-disjoint path cover quiere decir que cada nodo 
	 debe pertenecer a exactamente un camino.
	 Para hallar el minimum Node-disjoint path cover podemos crear un grafo bipartito
	 donde separamos cada nodo u en uin (2*u)(right) y uout (2*u + 1)(left), entonces 
	 para cada arista u, v conectamos uout con vin. Despues hallamos el matching y 
	 esas son las aristas que vamos a elegir para armar el Node-disjoint path cover, 
	 entonces el total de caminos sera n - c, siendo n la cantidad de nodos en el grafo 
	 original y c la cantidad de aristas en el matching.
   - General path cover en un DAG:
     El minimum path cover se puede hallar de manera similar al minimum node-disjoint
	 path cover, pero esta vez vamos a agregar una arista de uout hacia vin si en el
	 grafo original se puede llegar desde u hasta v (posiblemente a traves de multiples
	 aristas).

   Para bipartitos:
   - Maximum Matching:
	 Se conectan todos los nodos de un lado left a un nuevo nodo source y todos los 
	 nodos de otro lado right a un nuevo nodo sink, le hace que las aristas del grafo
	 original tengan direccion desde su correspondiente nodo en left hacia su 
	 correspondiente nodo en right y finalmente se calcula el flujo. Las aristas de
	 left hacia right con flujo = 1 son las	que haran parte del matching.
   - Minimum vertex cover:
     Es el minimo conjunto de nodos tal que cada arista del grafo tiene al menos 
	 uno de los sus nodos en dicho conjunto. El tamaño del minimum vertex cover es el mismo
	 del maximum matching. Para hallar cuales vertices pertenecen podemos ver entre la lista 
	 de adyacencia de source cuales nodos hacen parte de right en el corte, ademas revisamos 
	 para cada vertice de left si este tiene a sink en su lista de adyacencia, estos tambien
	 hacen parte del minimum vertex cover.
   - Maximum independent set:
     Es el mayor conjunto de nodos tal que no hay 2 nodos del conjunto conectados por
	 una arista. Todos los nodos que no hacen parte del minimum vertex cover hacen parte
	 del maximum independent set, por lo tanto el tamaño de este es el total de nodos
	 del grafo menos el tamaño del maximum matching.
*/

struct comp{
    bool operator() (pii a, pii b){
        if(a.se == b.se)
            return a.fi < b.fi;
        return a.se < b.se;
    }
};

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0){
		adj[a].pb({b, (int)adj[b].sz, c, c});
		adj[b].pb({a, (int)adj[a].sz - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f){
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].sz; i++){
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))){
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t){
		ll flow = 0; q[0] = s;
		for(ll L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int> (q.sz);
			int qi = 0, qe = lvl[s] = 1;
			while(qi < qe && !lvl[t]){
				int v = q[qi++];
				for(Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; } // 1 si es parte del lado de source
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n; cin>>n;
    Dinic graph(n + 2); //Crear un grafo para usar Dinic

	// Agregar una arista desde s hasta d con capacidad c
	// Tener en cuenta que es un grafo dirigido, si se quiere un grafo no dirigido,
	// agregar la misma arista en direccion contraria
    graph.addEdge(s, d, c);
    
    graph.calc(source, sink); //Maximo flujo desde source hast sink

	// Para reconstruir el flujo enviado por cuales aristas
	for(int u = 0; u < N; ++u){
		for(auto &e : graph.adj[u]){
			int v = e.to;
			ll f = e.flow(); // f = flujo enviado desde u a v

			// Mostrar solo aristas "reales" (no las de retroceso)
			if(f > 0 && e.oc > 0){
				cout << "Flujo de " << u << " a " << v << ": " << f << endl;
			}
		}
	}

	// Para hallar los vertices que pertenecen al minimum vertex cover
	// Sea source = 0, el lado izquierdo del bipartito los nodos de 1 hasta n,
	// el lado derecho los nodos de n+1 hasta 2*n y sink = 2*n + 1
	for(auto &e : graph.adj[0]){ // Recorremos la lista de adyacencia de source
        int v = e.to;
        if(!graph.leftOfMinCut(v)) cout<<1<<' '<<v<<endl; // Si v no esta en left en el corte, hace parte del MVC
    }
    for(int u = n+1; u <= 2*n; u++){
        if(!graph.leftOfMinCut(u)) continue; // Recorremos los nodos que hacen parte de left en el corte y en la derecha del bipartito
        for(auto &e : graph.adj[u]){
			int v = e.to;
            if(v != 2*n + 1) continue; // Si tiene arista hacia sink, hace parte del MVC
            cout<<2<<' '<<u - n<<endl;
            break;
		}
    }
 
    return 0;
}