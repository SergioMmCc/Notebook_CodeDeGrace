#include <bits/stdc++.h>
using namespace std;

const int MAXT = 200000;
const int LOG = 18;
vector<vector<int>> graph(MAXT, vector<int>()), up(MAXT, vector<int>(LOG, 0));
vector<int> depth(MAXT, -1), order;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void BFS () {
    depth[0] = 0;
    int v;
    pq.push({0, 0});
    while(!pq.empty()) {
        v = pq.top().second;
        order.push_back(v);
        pq.pop();
        for(int u : graph[v]) {
            if(depth[u] == -1) {
                depth[u] = depth[v] + 1;
                up[u][0] = v;

                for(int j = 1; j < LOG; j++) 
                    up[u][j] = up[up[u][j-1]][j-1];
                pq.push({depth[u], u});
            }
        }
    }
}

int LCA (int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j))
            a = up[a][j];
    }
    if(a == b)
        return a;
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int vertex, edges; cin >> vertex >> edges;
    int u, v;
    long long result = 0;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFS();

    for(int i = 0; i < vertex - 1; i++) {
        u = order[i];
        v = order[i+1];
        result += (long long)(depth[u] + depth[v] - (depth[LCA(u, v)] * 2));
    }
    cout << result << endl;

    return 0;
}