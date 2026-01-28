#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void BFS(int n, vector<int>& ans, vector<int> graph[]){
    ans[1] = 1;
    queue<int> q;
    q.push(1);
    vector<bool> visited(n+1);
    visited[1] = 1;
    vector<bool> used(2*n + 1);
    used[1] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();

        int aux = ans[u] + 4;
        for(int v : graph[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = 1;

            if(!used[ans[u] + 1]){
                used[ans[u] + 1] = 1;
                ans[v] = ans[u] + 1;
            }
            else{
                while(used[aux]) aux += 2;
                used[aux] = 1;
                ans[v] = aux;
            }
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<int> graph[n+1];
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> ans(n+1);
    BFS(n, ans, graph);
    for(int i = 1; i <= n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}