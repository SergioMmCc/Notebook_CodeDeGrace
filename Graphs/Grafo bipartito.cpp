void DFS(int u) {
    for (auto v: g[u]) {
        if (!color[v]) {
            color[v] = 3 - color[u];
            DFS(v);
        } 
        else if (color[v] + color[u] != 3)
            bipartito = false;
    }
}