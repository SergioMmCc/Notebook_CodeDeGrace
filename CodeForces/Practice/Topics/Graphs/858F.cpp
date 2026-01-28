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
vector<vector<int>> ans;

bool DFS(int x, int prev){
    visited[x] = 1;
    vector<int> edge;
    for(int y : graph[x]){
        if(y == prev) continue;
        if(visited[y]){
            if(x < y) edge.pb(y);
        }
        else{
            if(DFS(y, x)) edge.pb(y);
        }
    }

    for(int i = 0; i < edge.sz / 2; i++){
        ans.pb({edge[2 * i], x, edge[2*i + 1]});
    }

    if(edge.sz % 2 == 0) return 1;
    if(prev != -1) ans.pb({edge[edge.sz - 1], x, prev});
    return 0;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i, -1);
    }

    cout<<ans.sz<<endl;
    for(int i = 0; i < ans.sz; i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;
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