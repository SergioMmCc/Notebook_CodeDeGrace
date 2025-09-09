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

const int maxn = 2e5 + 1;
const int LOG = 19; //El logaritmo base 2 del numero maximo de nodos
vector<vector<int>> graph(maxn), up(maxn, vector<int>(LOG)); // up[a][i] guarda el ancestro que está a 2^i distancia de a
vector<int> depth(maxn, -1);


/* Este algoritmo sirve para calcular el minimo ancestro
   comun (Lowest Common Ancestor) entre dos nodos especificos.
   Cada query tiene una complejidad de 0(lg(n)), siendo n
   el número de nodos del grafo, gracias al Binary Lifting.
   El algoritmo toma un nodo en especifico como raiz y calcula 
   la profundidad de cada nodo según el número minimo de nodos 
   que debe atravesar para llegar al nodo raíz, esto se calcula
   mediante un BFS. */

// Esta implementación sirve para grafos no dirigidos y dirigidos

void BFS(int s) {
    depth[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int v = pq.top().se;
        pq.pop();
        for(int u : graph[v]) {
            if(depth[u] == -1) {
                depth[u] = depth[v] + 1;
                up[u][0] = v;

                for(int j = 1; j < LOG; j++) 
                    up[u][j] = up[up[u][j-1]][j-1];
                pq.push({depth[u], u});
            }
        }
    }
}

int LCA (int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    // Este ciclo pone a y b en el mismo nivel
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j))
            a = up[a][j];
    }
    if(a == b)
        return a;
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main(){
    int n, m; cin>>n>>m;
    for(int i = 2; i <= n; i++){
        int u; cin>>u;
        graph[u].pb(i);
    }

    BFS(1);

    while(m--){
        int u, v; cin>>u>>v;
        cout<<LCA(u, v)<<endl;
    }

    return 0;
}