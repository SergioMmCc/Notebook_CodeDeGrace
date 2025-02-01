const int maxn = 2e5 + 2;
vector<vector<int>> graph(maxn);
vector<int> color(maxn);
bool bipartito = 1;

void DFS(int u){
    for(auto v : graph[u]) {
        if(!color[v]){
            color[v] = 3 - color[u];
            DFS(v);
        } 
        else if(color[v] + color[u] != 3)
            bipartito = false;
    }
}