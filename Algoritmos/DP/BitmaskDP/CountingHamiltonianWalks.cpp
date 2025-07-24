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

const int mod = 1e9 + 7, maxn = 20;
int dp[maxn][1 << maxn];
vector<vector<int>> graph(20);

// - Cuenta la cantidad de caminos hamiltonianos que contiene un grafo
//   empezando en el vertice 1, pasando por todos los vertices 
//   exactamente una vez y terminando en el vertice n
// - Para contar la cantidad de caminos hamiltonianos que contiene un
//   grafo iniciando y terminando en cualquier vertice, inicializamos
//   dp[i][1 << i] en 1, para i desde 1 hasta n y finalmente sumamos
//   dp[i][2^n - 1] para i desde 1 hasta n
// - Para contar la cantidad de caminos simples que contiene un grafo
//   (que pasa por algunos vertices exactamente una vez) hacemos el
//   mismo dp que en el caso anterior pero esta vez sumamos cada
//   estado cuyo subconjunto contenga 2 o mas vertices y finalmente
//   dividimos la respuesta entre 2 ya que de esa forma se esta
//   contando 2 veces cada camino (en ambas direcciones)

// Complejidad: O(2^n * n^2)
void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        graph[u].pb(v);
    }

    int lim = 1 << n;
    dp[0][1] = 1;
    for(int j = 1; j < lim; j++){

        // Estos 2 ifs eliminan muchas posibilidades, así que pueden ayudar a evitar TLE
        if(!(j & 1)) continue; // Si no he pasado por la fuente (1 << s)
        if(j & (1 << (n-1)) && j < lim - 1) continue; // Si llego al destino sin haber pasado por los demas (1 << d)

        for(int i = 0; i < n; i++){

            if(!(j & (1 << i))) continue;

            for(int v : graph[i]){
                if(j & (1 << v)) continue;
                dp[v][j | (1 << v)] += dp[i][j];
                dp[v][j | (1 << v)] %= mod;
            }
        }
    }

    cout<<dp[n-1][lim - 1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}