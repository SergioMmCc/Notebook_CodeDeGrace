#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;
typedef pair<pii, ll> piil;
typedef pair<int, ll> pil;

const int maxn = 1e5 + 1;
const ll inf = 1e15;

struct comp{
    bool operator() (pil a, pil b){
        return a.second > b.second;
    }
};

void dijkstra(int source, int n, vector<vector<pil>>& graph, vector<ll>& d){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[source] = 0;
    priority_queue<pil, vector<pil>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first, w = pq.top().second;
        pq.pop();
        if(d[u] < w) continue;
        for(pil v : graph[u]){
            if(d[v.first] > w + v.second){
                d[v.first] = w + v.second;
                pq.push({v.first, d[v.first]});
            }
        }
    }
}

vector<piil> calc(int n, int t, map<piil, int>& edges, vector<pil>& ans, vector<ll>& ds, vector<ll>& dt, vector<vector<pil>>& graph){
    vector<piil> possible;
    vector<int> visited(n+1); visited[t] = 1;
    queue<int> q; q.push(t);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(pii edge : graph[u]){
            int v = edge.first; ll w = edge.second;
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }

            ll dist = ds[v] + dt[u] + w;
            // cout<<"u -> "<<u<<" dt[u] -> "<<dt[u]<<" v -> "<<v<<" ds[v] -> "<<ds[v]<<" w -> "<<w<<endl;
            int index = edges[{{v, u}, w}]; 
            // cout<<"index -> "<<index<<endl;
            if(dist == ds[t]){
                possible.pb({{v, u}, w});
                ans[index] = {2, 0};
            }
            else{
                if(ds[v] + dt[u] + 1 < ds[t]){
                    ll len = ds[t] - (ds[v] + dt[u] + 1);
                    ll cost = w - len;
                    ans[index] = {1, cost};
                }
            }
        }
    }

    return possible;
}

void BFS(int s, int t, int n, vector<pil>& ans, map<piil, int>& edges, vector<vector<pil>>& graph, vector<int>& inDegree){
    vector<bool> visited(n+1); visited[s] = 1;
    queue<int> q; q.push(s);
    int roads = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u != t) roads += graph[u].sz - 1;
        // cout<<"u -> "<<u<<" roads -> "<<roads<<endl;
        for(pil edge : graph[u]){
            int v = edge.first; ll w = edge.second;
            int index = edges[{{u, v}, w}];
            if(roads > 1){
                if(w > 1) ans[index] = {1, 1};
                else ans[index] = {0, 0};
            }
            else ans[index] = {2, 0};

            if(visited[v]) roads--;
            visited[v] = 1;
            inDegree[v]--;
            if(!inDegree[v]) q.push(v);
        }
    }
}

void solver(){
    int n, m, s, t; cin>>n>>m>>s>>t;
    vector<vector<pil>> inGraph(n+1), outGraph(n+1);
    map<piil, int> edges; vector<piil> edgesAux;
    vector<pil> ans(m, {0, 0});
    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin>>u>>v>>w;
        edges[{{u, v}, w}] = i;
        edgesAux.pb({{u, v}, w});
        inGraph[u].push_back({v, w});
        outGraph[v].push_back({u, w});
    }
    vector<ll> ds(n+1), dt(n+1);
    dijkstra(s, n, inGraph, ds);
    dijkstra(t, n, outGraph, dt);

    // cout<<"ds[t] -> "<<ds[t]<<endl;
    vector<piil> possible = calc(n, t, edges, ans, ds, dt, outGraph);
    vector<vector<pil>> auxGraph(n+1);
    vector<int> inDegree(n+1);
    for(piil edge : possible){
        int u = edge.first.first, v = edge.first.second; ll w = edge.second;
        inDegree[v]++;
        auxGraph[u].pb({v, w});
    }
    BFS(s, t, n, ans, edges, auxGraph, inDegree);

    for(int i = 0; i < m; i++){
        // int u = edgesAux[i].first.first, v = edgesAux[i].first.second; ll w = edgesAux[i].second;
        int index = edges[edgesAux[i]];
        if(!ans[index].first) cout<<"NO"<<endl;
        else if(ans[index].first == 1) cout<<"CAN "<<ans[index].second<<endl;
        else cout<<"YES"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}