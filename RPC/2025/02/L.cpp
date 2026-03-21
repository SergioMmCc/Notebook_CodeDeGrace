#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;

const int maxn = 1e5 + 1;
const ld inf = 1e15;
typedef pair<int, ld> pid;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef pair<pid, pdd> piddd;
vector<piddd> graph[maxn];

struct comp{
    bool operator() (pid a, pid b){
        return a.second > b.second;
    }
};

void dijkstra(int source, int n, vector<ld>& d, ld t){
    for(int i = 1; i <= n; i++){
        d[i] = inf;
    }   
    d[source] = 0.0;
    priority_queue<pid, vector<pid>, comp> pq;
    pq.push({source, 0.0});
    while(!pq.empty()){
        int u = pq.top().first; ld w = pq.top().second;
        pq.pop();
        if(d[u] < w) continue;
        for(piddd edge : graph[u]){
            int v = edge.first.first; ld x = edge.first.second, va = edge.second.first, vd = edge.second.second;
            ld add;
            if(w >= t){
                add = w + x / vd;
            }
            else{
                if(w + (x / va) <= t){
                    add = w + x / va;
                }
                else{
                    ld dif = t - w;
                    ld aux = dif * va;
                    add = w + (aux / va) + ((x - aux) / vd);
                }
            }
            if(d[v] > add){
                d[v] = add;
                pq.push({v, add});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m; ld t; cin>>n>>m>>t;
    for(int i = 0; i < m; i++){
        int u, v; ld x, va, vd; cin>>u>>v>>x>>va>>vd;
        graph[u].push_back({{v, x}, {va, vd}});
        graph[v].push_back({{u, x}, {va, vd}});
    }
    vector<ld> d(n+1);
    dijkstra(1, n, d, t);
    cout<<fixed<<setprecision(10)<<d[n]<<endl;

    return 0;
}