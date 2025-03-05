#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int maxn = 1e5 + 1;
long long const inf = 2e9;
typedef pair<int, int> pii;
vector<pii> graph[maxn];

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void dijkstra(int source, int n, vector<int>& d, vector<int>& parent){
    for(int i = 1; i <= n; i++){
        d[i] = inf;
        parent[i] = -1;
    }   
    d[source] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first, w = pq.top().second;
        pq.pop();
        if(d[u] < w) continue;
        for(pii v : graph[u]){
            if(d[v.first] > w + v.second){
                d[v.first] = w + v.second;
                parent[v.first] = u;
                pq.push({v.first, d[v.first]});
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
    vector<int> d(n+1), parent(n+1);
    dijkstra(1, n, d, parent);
    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" d: "<<d[i]<<" parent: "<<parent[i]<<endl;

    return 0;
}