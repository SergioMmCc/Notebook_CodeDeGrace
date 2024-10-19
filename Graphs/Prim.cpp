#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100000

long long const inf = 2e9;

typedef pair<int, int> pii;
vector<pii> graph[MAXN+1];

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void prim(int source, int n, vector<int>& distance, vector<int>& parent){
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
        for(pii v : graph[u]){
            if(distance[v.first] > v.second){
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
    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" distance: "<<distance[i]<<" parent: "<<parent[i]<<endl;
    cout<<endl;
    
    //Para calcular el peso total en el MST
    int totalWeight = 0;
    for(int i = 1; i <= n; i++)
        totalWeight += distance[i];
    cout<<"Peso total del minimal spanning tree: "<<totalWeight<<endl;

    return 0;
}