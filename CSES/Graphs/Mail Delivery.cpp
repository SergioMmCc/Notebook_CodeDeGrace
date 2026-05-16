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
    Source: https://usaco.guide/CPH.pdf#page=183

    Un camino euleriano es aquel que pasa exactamente una vez 
    por cada arista del grafo. Un circuito euleriano es un
    camino euleriano que inicia y termina en el mismo nodo.

    Un camino euleriano existe si todas las aristas pertenecen 
    al mismo componente y:
    - El grado de todos los nodos es par (en este caso tambien
      es un circuito)
    - El grado de exactamente 2 nodos es impar y el del resto
      es par (en este caso el camino inicia en uno de estos y
      termina en el otro)

    Implementacion del algoritmo de Hierholzer para hallar un
    ciclo euleriano. En caso de querer hallar un camino euleriano,
    agregar una arista entre los nodos con grado impar para 
    realizar el proceso y despues se elimina.
    Complejidad: O(E)
*/

void DFS(int u, vector<vii>& graph, vb& used, vi& ans){
    while(!graph[u].empty()){
        pii edj = graph[u].back();
        int v = edj.fi, idx = edj.se;
        graph[u].pop_back(); // Eliminar arista ya visitada
        if(used[idx]) continue; // En caso de ya haber visitado esta arista partiendo desde v
        used[idx] = 1;
        DFS(v, graph, used, ans);
    }
    ans.pb(u);
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vii> graph(n+1);
    vi degree(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb({v, i});
        graph[v].pb({u, i});
        degree[u]++;
        degree[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(degree[i] & 1){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }

    vb used(m+1);
    vi ans;
    DFS(1, graph, used, ans);

    if(sz(ans) != m+1){ // En caso de que no todas las aristas estuvieran en el mismo componente
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    for(int x : ans) cout<<x<<' ';
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}