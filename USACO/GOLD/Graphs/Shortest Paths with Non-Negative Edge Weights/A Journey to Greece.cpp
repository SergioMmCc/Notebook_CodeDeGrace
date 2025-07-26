#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 2e4, maxp = 16, inf = 1e9;
vector<vector<pii>> graph(maxn);

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

// Complejidad O(m*log(n))
void dijkstra(int source, int n, vector<int>& d){
    for(int i = 0; i < n; i++) d[i] = inf;
    d[source] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first; ll w1 = pq.top().second;
        pq.pop();
        if(d[u] < w1) continue;
        for(pii edge : graph[u]){
            int v = edge.first; ll w2 = edge.second;
            if(d[v] > w1 + w2){
                d[v] = w1 + w2;
                pq.push({v, d[v]});
            }
        }
    }
}

void solver(){
    int n, p, m, g, t; cin>>n>>p>>m>>g>>t;
    vector<int> a; a.pb(0);
    map<int, int> comp; comp[0] = 0;
    int count = 0;
    for(int i = 0; i < p; i++){
        int u, w; cin>>u>>w;
        g -= w;
        if(u){
            a.pb(u);
            count++;
            comp[u] = count;
        }
    }

    if(a.sz == 1){
        cout<<(g >= 0 ? "possible without taxi" : "impossible")<<endl;
        return;
    }

    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    p = a.sz;
    vector<vector<pii>> aux(p);
    for(int i : a){
        vector<int> d(n);
        dijkstra(i, n, d);
        int u = comp[i];
        for(int j = 0; j < n; j++){
            if(i != j && comp.find(j) != comp.end()) aux[u].pb({comp[j], d[j]});
        }
    }

    // Inicializar el dp
    int lim = 1 << p;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(p, vector<int>(lim, inf)));
    for(pii e : aux[0]){
        dp[0][e.fi][1 << e.fi] = e.se;
        dp[1][e.fi][1 << e.fi] = t;
    }

    for(int mask = 0; mask < lim; mask++){
        if(mask & 1 && mask != lim - 1) continue;
        for(int u = 0; u < p; u++){
            if(mask && (1 << u) == 0) continue;

            // Usando aristas normales
            for(pii e : aux[u]){
                int v = e.fi, w = e.se;
                if(mask & (1 << v) == 0) continue;
                dp[0][u][mask] = min(dp[0][u][mask], w + dp[0][v][mask ^ (1 << u)]);
                dp[1][u][mask] = min(dp[1][u][mask], w + dp[1][v][mask ^ (1 << u)]);
            }

            // Usando el taxi
            for(int v = 0; v < p; v++){
                if(v == u || mask & (1 << v) == 0) continue;
                dp[1][u][mask] = min(dp[1][u][mask], t + dp[0][v][mask ^ (1 << u)]);
            }
        }
    }

    if(dp[0][0][lim - 1] <= g) cout<<"possible without taxi"<<endl;
    else if(dp[1][0][lim - 1] <= g) cout<<"possible with taxi"<<endl;
    else cout<<"impossible"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}