#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXT = 1001;
const int LOG = 12;
vector<vector<int>> graph(MAXT, vector<int>()), up(MAXT, vector<int>(LOG, 0));
vector<int> depth(MAXT, -1), weight(MAXT);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void BFS () {
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

vector<int> visited(MAXT);
void DFS(int u){
    visited[u] = 1;
    for(int v : graph[u]){
        if(!visited[v]){
            weight[v] += weight[u];
            DFS(v);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;cin>>n>>m;
    set<int> inicio, salida;
    for(int i = 1; i <= n; i++){
        cin>>weight[i];
        inicio.insert(i);
        salida.insert(i);
    }
       
    for(int i = 0; i < m; i++){
        int u, v;cin>>u>>v;
        if(inicio.find(v) != inicio.end())
            inicio.erase(v);
        if(salida.find(u) != salida.end())
            salida.erase(u);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(auto it : inicio) {
        graph[0].push_back(it);
        graph[it].push_back(0);
    }
    
    DFS(0);   
    BFS();
    
    int ans = 2e9;
    for(set<int>::iterator it1 = salida.begin(); it1 != salida.end(); ++it1){
        for(set<int>::iterator it2 = next(it1); it2 != salida.end(); ++it2){
            ans = min(ans, weight[*it1] + weight[*it2] - weight[LCA(*it1, *it2)]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}