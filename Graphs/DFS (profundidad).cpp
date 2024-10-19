#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXT 100000

vector<int> graph[MAXT + 1];

void DFS(int u, vector<int>& visited, vector<int>& parent) {
    visited[u] = 1;
    for(int v : graph[u]) {
        if(!visited[v]) {
            parent[v] = u;
            DFS(v, visited, parent);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1, 0), parent(n+1, -1);

    DFS(1, visited, parent);

    for(int i = 1; i <= n; i++)
        cout<<"vertex: "<<i<<" parent: "<<parent[i]<<endl;

    return 0;
}
