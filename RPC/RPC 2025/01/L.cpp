#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int MAXT = 200000;
const int LOG = 18;
vector<vector<int>> tree(MAXT), forest(MAXT), up(MAXT, vector<int>(LOG, 0));
vector<bool> visited(MAXT, 1);
int dp[MAXT][2];
vector<int> depth(MAXT, -1);
priority_queue<pii, vector<pii>, greater<pii>> pq;

void BFS(){
    depth[0] = 0;
    int v;
    pq.push({0, 0});
    while(!pq.empty()) {
        v = pq.top().second;
        pq.pop();
        for(int u : tree[v]) {
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

    // Este ciclo pone a y b en el mismo nivel
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

void calc(int n, int parent){
    dp[n][0] = 0; dp[n][1] = 1;
    for(int i : forest[n]){
        if(i == parent) continue;
        visited[i] = 1;
        calc(i, n);
    }

    for(int i : forest[n]){
        if(i == parent) continue;
        dp[n][0] += dp[i][1];
        dp[n][1] += min(dp[i][0], dp[i][1]);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    BFS();

    set<pii> edges; set<int> vertex;
    for(int i = 0; i < k; i++){
        int a, b; cin>>a>>b;
        if(depth[b] > depth[a]) swap(a, b);
        
        int dist = depth[a] + depth[b] - 2 * depth[LCA(a, b)];

        if(dist % 2){ // Conjunto de 2 nodos
            int mid = dist / 2;
            for(int j = LOG - 1; j >= 0; j--){
                if(mid & (1 << j)) a = up[a][j];
            }

            b = up[a][0];
            edges.insert({a, b});
        }

        else{
            int mid = dist / 2;
            for(int j = LOG - 1; j >= 0; j--){
                if(mid & (1 << j)) a = up[a][j];
            }
            vertex.insert(a);
        }
    }

    for(pii edge : edges){
        int a = edge.first, b = edge.second;
        if(vertex.find(a) == vertex.end() && vertex.find(b) == vertex.end()){
            forest[a].pb(b);
            forest[b].pb(a);
            visited[a] = visited[b] = 0;
        }
    }

    int ans = vertex.sz;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            calc(i, -1);
            
            ans += min(dp[i][0], dp[i][1]);
        }
    }
    cout<<ans<<endl;

    return 0;
}