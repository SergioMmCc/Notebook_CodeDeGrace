#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

int const maxn = 2e5 + 5;

vector<int> graph[maxn];
vector<bool> visited(maxn);

int BFS(int s){
    int elements = 1;
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(!visited[v]){
                elements++;
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    return elements;
}

int BFS_visit(int n){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            int aux = BFS(i);
            ans = max(ans, aux);
        }
    }

    return ans;
}

void solver(){
    int n, m;cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int ans = BFS_visit(n);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}