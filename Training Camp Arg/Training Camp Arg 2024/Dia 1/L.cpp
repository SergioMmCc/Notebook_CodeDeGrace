#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 200001
typedef pair<int, int> pii;

vector<int> graph[MAXN];
map<pii, int> edges;

void BFS(int n, int m) {
    vector<int> ans(m+1, -1);
    vector<int> color(n+1, -1);
    vector<bool> visited(n+1, false);
    //1 si hay caminos saliendo
    //2 si hay caminos entrando
    //-1 si todavia no he definido nada
    int u, change;
    map<pii, int>::iterator it;
    
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        u = q.front(); q.pop();
        if(visited[u] == true)
            continue;
        visited[u] = true;
        for(int v : graph[u]) {
            if((color[u] == -1 || color[u] == 1) && (color[v] == -1 || color[v] == 2)) {
                color[u] = 1;
                color[v] = 2;
                
                it = edges.find({u, v});
                if(it != edges.end())
                    ans[it->second] = 1;
                else {
                    it = edges.find({v, u});
                    ans[it->second] = 0;
                }
            }
            
            else if((color[u] == -1 || color[u] == 2) && (color[v] == 1 || color[v] == -1)) {
                color[u] = 2;
                color[v] = 1;
                
                it = edges.find({v, u});
                if(it != edges.end())
                    ans[it->second] = 1;
                else {
                    it = edges.find({u, v});
                    ans[it->second] = 0;
                }
            }
            
            else {
                cout<<"NO"<<endl;
                return;
            }
            
            q.push(v);
        }
    }
    
    cout<<"YES"<<endl;
    for(int i = 1; i <= m; i++)
        cout<<ans[i];
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m, u, v;
    cin>>n>>m;
    
    for(int i = 1; i  <= m; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[{u, v}] = i;
    }
    BFS(n, m);

    return 0;
}