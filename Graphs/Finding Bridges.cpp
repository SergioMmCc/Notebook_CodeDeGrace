#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;
vector<vector<int>> graph(maxn);
vector<bool> visited(maxn);
vector<int> dp(maxn), sons[maxn], father(maxn);
set<pii> used;

void DFS(int u, int prev){
    visited[u] = 1;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(visited[v]){
            if(used.find({v, u}) != used.end()) continue;
            dp[u]++;
            dp[v]--;
            used.insert({u, v});
            continue;
        }
        sons[u].pb(v);
        father[v] = u;
        DFS(v, u);
    }
}

int calc(int u){
    for(int v : sons[u]) dp[u] += calc(v);
    return dp[u];
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    // 1 es la raiz en este caso
    DFS(1, -1); // Crear DFS tree
    calc(1); // Calcular el dp

    for(int i = 2; i <= n; i++){
        // Si dp[i] == 0, la arista que conecta i y su padre son un puente
        if(!dp[i]) cout<<"Bridge: "<<father[i]<<" - "<<i<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}