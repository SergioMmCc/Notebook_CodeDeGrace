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

const int maxn = 401;
vector<set<int>> comp(maxn);
vector<vector<int>> graph(maxn);

int BFS1(int n){
    vector<int> d(n+1); vector<bool> vis(n+1); vis[1] = 1;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    return vis[n] ? d[n] : n+1;
}

int BFS2(int n){
    vector<int> d(n+1); vector<bool> vis(n+1); vis[1] = 1;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : comp[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    
    return vis[n] ? d[n] : n+1;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            comp[i].insert(j);
        }
    }

    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        if(u > v) swap(u, v);
        comp[u].erase(v);
        comp[v].erase(u);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int ans = max(BFS1(n), BFS2(n));
    cout<<(ans == n+1 ? -1 : ans);
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