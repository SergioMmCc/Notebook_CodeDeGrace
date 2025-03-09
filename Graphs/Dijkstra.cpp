#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 1, inf = 1e9;
vector<pii> graph[maxn];

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

// Complejidad O(m*log(n))
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

void solver(){
    int n, m, s; cin>>n>>m>>s;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> d(n+1), parent(n+1);
    dijkstra(s, n, d, parent);
    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" d: "<<d[i]<<" parent: "<<parent[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}