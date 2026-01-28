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
const int maxn = 2e5 + 5;
vector<vector<int>> graph(maxn);
vector<bool> visited(maxn);
vector<int> dp(maxn), sons[maxn], father(maxn);
set<pii> used;
vector<ll> cont(maxn);

void DFS(int u, int prev){
    visited[u] = 1;
    for(int v : graph[u]){
        if(v == prev) continue;
        if(visited[v]){
            if(used.find({v, u}) != used.end()) continue;
            dp[u]++;
            dp[v]--;
            used.insert({u, v});
            continue;
        }
        sons[u].pb(v);
        used.insert({u, v});
        father[v] = u;
        DFS(v, u);
        cont[u] += cont[v];
    }
    cont[u]++;
}

int calc(int u){
    for(int v : sons[u]) dp[u] += calc(v);
    return dp[u];
}

void solver(){
    ll n, m; cin>>n>>m;
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        visited[i] = 0;
        dp[i] = 0;
        sons[i].clear();
        father[i] = 0;
        cont[i] = 0;
    }
    used.clear();

    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    // 1 es la raiz en este caso
    // Tener en cuenta que si el grafo no es conexo y se quieren hallar puentes
    // en algun componente, tocaria lanzar un DFS para cada componente y en la
    // iteracion final saltarse todos los vertices desde los cuales se lanzo algun
    // DFS
    DFS(1, -1); // Crear DFS tree
    calc(1); // Calcular el dp

    ll ans = (n * (n-1)) / 2;
    for(int i = 2; i <= n; i++){
        // Si dp[i] == 0, la arista que conecta i y su padre son un puente
        if(!dp[i]){
            // cout<<"i -> "<<i<<" par -> "<<father[i]<<" cont -> "<<cont[i]<<endl;
            ll ot = ((n - cont[i]) * (n - cont[i] - 1)) / 2;
            ot += (cont[i] * (cont[i]-1)) / 2;
            ans = min(ans, ot);
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}