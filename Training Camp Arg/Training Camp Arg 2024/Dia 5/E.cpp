#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1e5 + 1;
vector<set<int>> graph(maxn);
set<int> visited;
queue<int> q;

void BFS () {
    int u;
    q.push(*visited.begin());
    visited.erase(visited.begin());
    set<int> visitedCopy = visited;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int i : visited) {
            set<int>::iterator it = graph[u].find(i);
            if(it == graph[u].end()) {
                q.push(i);
                visitedCopy.erase(i);
            }
        }
        visited = visitedCopy;
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m, u, v, nComponents = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        visited.insert(i);
    for(int i = 0; i < m; i++) {
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    while(visited.size() > 0) {
        nComponents++;
        BFS();
    }
    nComponents--;

    cout<<nComponents<<endl;

    return 0;
}