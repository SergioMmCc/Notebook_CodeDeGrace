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

/*
  - Implementacion 0-index
  - Complejidad O(2^n * n^2)
  - Halla el minimo peso para recorrer todos los vertices del grafo
    iniciando en el vertice 0 (teniendo en cuenta que para moverse entre
    2 vertices solo se pueden usar aristas entre ellos).

  - Otras aplicaciones:
    - Para hallar el camino hamiltoniano de menos costo (empezando en 
      cualquier vertice) simplemente se inicializa el DP con 
      dp[i][1<<i] = 0, para i entre 0 y n-1.
    - Para pedir que termine en algun vertice en especifico, por ejemplo n-1, 
      simplemente hacer que la unica mascara valida que contenga n-1 sea lim-1, 
      y que solo sea valida cuando el vertice final sea n-1, es decir, 
      dp[n-1][lim-1].
    - Para hallar el ciclo hamiltoniano mas corto, podemos elegir el vertice
      0 como inicial y marcar dp[i][1<<i] = distancia(0, i) para cada vertice 
      entre 1 y n-1 (dejamos dp[0][1] = inf) y luego correr el algoritmo 
      obligando que el vertice 0 sea el vertice final
*/

const int maxn = 20, inf = 1e9;
vector<vector<pii>> graph(maxn);

void solver(){
    int n, m; cin>>n>>m;

    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w; u--; v--;
        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    // Inicializar el dp
    int lim = 1 << n;
    vector<vector<int>> dp(n, vector<int>(lim, inf));
    dp[0][1] = 0;

    for(int mask = 1; mask < lim; mask++){
        if(mask & 1 == 0) continue; // Si no he visitado el vertice inicial
        for(int u = 0; u < n; u++){
            if(mask && (1 << u) == 0) continue; // Si no he visitado la arista donde quiero finalizar

            for(pii e : graph[u]){
                int v = e.fi, w = e.se;
                if(mask & (1 << v) == 0) continue; // Si no he visitado el vertice desde el cual vendria
                dp[u][mask] = min(dp[u][mask], w + dp[v][mask ^ (1 << u)]);
            }
        }
    }

    int ans = inf;
    for(int i = 1; i < n; i++) ans = min(ans, dp[i][lim - 1]);
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