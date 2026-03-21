#include <bits/stdc++.h>
using namespace std;
 
vector<vector<vector<int>>> G(101, vector<vector<int>>(101, vector<int>()));
 
bool solver(int a, int b, int c) {
    int u;
    vector<int> visited(101, 0);
    if(G[c][a].size() == 0)
        return false;
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int i : G[c][u]) {
            if(visited[i] == 1)
                continue;
            if(i == b)
                return true;
            
            q.push(i);
            visited[i] = 1;
        }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        G[c][u].push_back(v);
        G[c][v].push_back(u);
    } 
    
    int q; cin >> q;
    int ans;
    while(q--) {
        ans = 0;
        cin >> u >> v;
        for(int i = 0; i <= 100; i++) {
            if(solver(u, v, i))
                ans++;
        }
        cout << ans << "\n";
    }
 
    return 0;
}