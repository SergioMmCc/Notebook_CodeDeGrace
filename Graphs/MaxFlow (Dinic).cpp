// Aplicado en grafos de flujo dirigidos con capacidades en las aristas
// Complejidad O(v^2 * E)
// Para grafos con capacidades unitarias o en redes densas O(sqrt(V) * E)

/* Otra aplicacion: Minimum vertex cut
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
   del minimum vertex cut. */


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

typedef pair<int, int> pii;

struct comp{
    bool operator() (pii a, pii b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
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
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, adj[b].size(), c, c});
		adj[b].push_back({a, adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for(ll L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int> (q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n; cin>>n;
    Dinic graph(n + 2); //Crear un grafo para usar Dinic

    graph.addEdge(s, d, c); //Agregar una arista desde s hasta d con capacidad c
    
    graph.calc(source, sink); //Maximo flujo desde source hast sink
 
    return 0;
}