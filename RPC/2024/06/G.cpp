#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXT 1000000

vector<int> graph[MAXT + 1], tree[MAXT + 1];
int sizeTree[MAXT + 1];

void generateTree (int root) {
    vector<int> visited(MAXT + 1);
    visited[root] = 1;
    queue<int> q; q.push(root);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : graph[u]) {
            if(visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
                tree[u].push_back(v);
            }
        }
    }
}

void DFS(int u) {
    int sizeT = 1;
    for(int v : tree[u]) {
        DFS(v);
        sizeT += sizeTree[v];
    }
    sizeTree[u] = sizeT;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;cin>>n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    generateTree(1);
    DFS(1);

    long long ans = 0; int rep = 0;
    for(int i = 2; i <= n; i++) {
        long long aux = (long long)sizeTree[i] * (n - sizeTree[i]);
        if(aux > ans) {
            ans = aux;
            rep = 1;
        }
        else if(aux == ans)
            rep++;
    }

    cout<<ans<<' '<<rep<<endl;
}