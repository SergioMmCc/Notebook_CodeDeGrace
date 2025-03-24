#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 200000

const int inf = 2e9;

typedef pair<int, int> pii;
vector<pii> graph[MAXN+1];

// Comparador para ordenar la cola de prioridad por el peso menor
struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second; // Para Maximal Spanning Tree cambiar '>' por '<'
    }
};

// Algoritmo de Prim para hallar el Minimal Spanning Tree de un grafo no dirigido y conexo
// Complejidad O(m * lg(n))
void prim(int source, int n, vector<int>& distance, vector<int>& parent){
    vector<bool> inQueue(n+1, 1);
    for(int i = 1; i <= n; i++){
        distance[i] = inf;
        parent[i] = -1;
    }   
    distance[source] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        if(!inQueue[u]) continue;
        inQueue[u] = 0;
        for(pii v : graph[u]){
            if(inQueue[v.first] && distance[v.first] > v.second){
                distance[v.first] = v.second;
                parent[v.first] = u;
                pq.push({v.first, distance[v.first]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m;cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> distance(n+1), parent(n+1);
    prim(1, n, distance, parent);
    
    //Para calcular el peso total en el MST
    long long totalWeight = 0;
    for(int i = 1; i <= n; i++)
        totalWeight += distance[i];
    cout<<totalWeight<<endl;

    return 0;
}