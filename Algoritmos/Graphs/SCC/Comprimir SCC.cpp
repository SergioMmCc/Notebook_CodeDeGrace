#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

/*
    Comprimir los SCC de un grafo dirigido en nodos individuales.
    Si el SCC tiene aristas de salida a otro SCC, se agregan a este 
    nuevo grafo. El grafo que se obtiene es un DAG. Tambien se 
    calcula el inDegree para realizar un toposort sobre este nuevo 
    grafo.
    Complejidad: O(n + m)
*/

void solver(){
    int n, m; cin>>n>>m;

    vector<vi> graph(n+1);
    vi d(n+1, -1), low(n+1), scc(n+1), reps(n+1, 0);
    vb stacked(n+1);
    stack<int> s;
    int ticks = 0, current_scc = 0;

    for(int i = 1; i <= m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
    }

    // Hallar los SCC
    for(int i = 1; i <= n; i++) if(d[i] == -1) tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);

    vector<vi> graph2(current_scc+1);
    vi inDegree(current_scc+1);
    for(int i = 1; i <= n; i++){
        for(int v : graph[i]){ // Buscar en las aristas del grafo original
            if(scc[v] != scc[i]){ // Verificar que la arista vaya a otro SCC
                graph2[scc[i]+1].pb(scc[v]+1);
                inDegree[scc[v]+1]++;
            }
        }
    }
}