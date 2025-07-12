const int maxn = 2e5 + 1, inf = 1e9;
vector<vector<int>> graph(maxn); 

void BFS(int s, int n){
    deque<pii> q; q.push_front({1, 0});
    vector<int> d(n+1, inf); d[s] = 0;

    while(!q.empty()){
        int u = q.front().fi, dis = q.front().se; q.pop_front();
        if(dis > d[u]) continue;

        for(int v : graph[u]){
            int add = 0;
            // if(cond) add++;
            if(d[v] > d[u] + add){
                d[v] = d[u] + add;
                if(!add) q.push_front({v, d[v]});
                else q.push_back({v, d[v]});
            }
        }
    }
}
