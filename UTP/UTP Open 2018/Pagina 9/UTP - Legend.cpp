#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 1;
vector<vector<int>> graph(maxn);

void BFS(int s, int n, vector<int>& d){
    vector<bool> visited(n+1);
    visited[s] = 1;
    queue<int> q; q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(visited[v]) continue;
            visited[v] = 1;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void solver(){
    int n, s, a, b, c, m; cin>>n>>s>>a>>b>>c>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> ds(n+1), da(n+1), db(n+1), dc(n+1);
    BFS(s, n, ds);
    BFS(a, n, da);
    BFS(b, n, db);
    BFS(c, n, dc);

    int maxi = -1, sa = 0, sb = 0, sc = 0;
    for(int i = 1; i <= n; i++){
        if(ds[i] + da[i] == ds[a]
        && ds[i] + db[i] == ds[b]
        && ds[i] + dc[i] == ds[c]){
            if(ds[i] > maxi){
                maxi = ds[i];
                sa = da[i]; sb = db[i]; sc = dc[i];
            }
        }
    }

    cout<<maxi<<' '<<sa<<' '<<sb<<' '<<sc<<endl;
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