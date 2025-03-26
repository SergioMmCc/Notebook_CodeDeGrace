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

const ll inf = 1e15;
const int maxn = 1e5 + 1;

typedef pair<int, ll> pil;
vector<vector<pil>> graph(maxn);

// Comparador para ordenar la cola de prioridad por el peso menor
struct comp{
    bool operator() (pil a, pil b){
        return a.second > b.second; // Para Maximal Spanning Tree cambiar '>' por '<'
    }
};

// Algoritmo de Prim para hallar el Minimal Spanning Tree de un grafo no dirigido y conexo
// Complejidad O(m * lg(n))
void prim(int source, int n, vector<ll>& d, vector<int>& parent){
    vector<bool> inQueue(n+1, 1);
    for(int i = 1; i <= n; i++){
        d[i] = inf;
        parent[i] = -1;
    }   
    d[source] = 0;
    priority_queue<pil, vector<pil>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        if(!inQueue[u]) continue;
        inQueue[u] = 0;
        for(pil edge : graph[u]){
            int v = edge.fi; ll w = edge.se;
            if(inQueue[v] && d[v] > w){
                d[v] = w;
                parent[v] = u;
                pq.push({v, d[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<ll> d(n+1);
    vector<int> parent(n+1);
    prim(1, n, d, parent);
    
    //Para calcular el peso total en el MST
    ll totalWeight = 0;
    for(int i = 1; i <= n; i++)
        totalWeight += d[i];
    cout<<totalWeight<<endl;

    return 0;
}