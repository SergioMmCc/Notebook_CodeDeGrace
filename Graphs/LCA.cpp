#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXT = 1001;
const int LOG = 12; //El logaritmo base 2 del numero maximo de nodos
vector<vector<int>> graph(MAXT, vector<int>()), up(MAXT, vector<int>(LOG, 0)); // up[a][i] guarda el ancestro que está a 2^i distancia de a
vector<int> depth(MAXT, -1);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


/* Este algoritmo sirve para calcular el minimo ancestro
   comun (Lowest Common Ancestor) entre dos nodos especificos.
   Cada query tiene una complejidad de 0(lg(n)), siendo n
   el número de nodos del grafo, gracias al Binary Lifting.
   El algoritmo toma un nodo en especifico como raiz (en este
   caso el nodo 0), y calcula la profundidad de cada nodo
   según el número minimo de nodos que debe atravesar para
   llegar al nodo raíz, esto se calcula mediante un BFS. */

// Esta implementación sirve para grafos no dirigidos

void BFS() {
    depth[0] = 0;
    int v;
    pq.push({0, 0});
    while(!pq.empty()) {
        v = pq.top().second;
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
    if(depth[a] < depth[b])
        swap(a, b);
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
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFS();

    /* Asumiendo que es un grafo conectado y que nuestro 
       nodo raíz es 0, vamos a calcular el LCA de cada par
       de nodos del grafo */

    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++)
            cout<<"El Lowest Common Ancestor entre "<<i<<" y "<<j<<" es: "<<LCA(i, j)<<endl;
    }

    return 0;
}