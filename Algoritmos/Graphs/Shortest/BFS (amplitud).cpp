#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXT 100000

int const inf = 2e9;
vector<int> graph[MAXT + 1];

void BFS(int source, int n, vector<int>& distance, vector<int>& parent){
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++) {
        distance[i] = inf;
        parent[i] = -1;
    }
    distance[source] = 0;
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(visited[v] == 0){
                visited[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance(n+1), parent(n+1);
    BFS(1, n, distance, parent);

    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" distance: "<<distance[i]<<" parent: "<<parent[i]<<endl;

    return 0;
}