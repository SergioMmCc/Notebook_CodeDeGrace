#include "../template.h"

const ll mod = 1e9 + 7;
const int maxn = 20;
ll dp[maxn][1 << maxn];
vector<vi> graph(maxn);

/*
- Complejidad: O(2^n * n^2).
- Cuenta la cantidad de caminos hamiltonianos que contiene un grafo
  empezando en el vertice 's', pasando por todos los vertices 
  exactamente una vez y terminando en el vertice 't'.
- dp[i][mask] cuenta la cantidad de caminos que inician en 's',
  pasan por los vertices de mask y terminan en 'i'.
- Para contar la cantidad de caminos hamiltonianos que contiene un
  grafo iniciando y terminando en cualquier vertice, se inicializa
  dp[i][1 << i] en 1, para i desde '0' hasta 'n-1' y finalmente en la
  respuesta se suma dp[i][2^n - 1] para i desde '0' hasta 'n-1'. Si el 
  grafo es no dirigido se debe dividir la respuesta entre 2 (division 
  modular).
  Si n=1, solo imprimir '1'.
- Para contar la cantidad de caminos simples que contiene un grafo
  (que pasa por al menos 2 vertices exactamente una vez) se hace el
  mismo dp que en el caso anterior pero en la respuesta se suma 
  cada estado cuya mascara contenga 2 o mas vertices. Si el grafo es
  no dirigido se divide la respuesta entre 2 (con division modular) ya 
  que de esa forma se esta contando 2 veces cada camino (en ambas 
  direcciones).
- Para contar la cantidad de ciclos hamiltonianos que tiene un grafo
  se toma el '0' como nodo inicial, y se cuentan todos los caminos 
  hamiltonianos que empiezan en este. Finalmente, para cada nodo
  1 <= i < n, si hay una arista que conecte i->0, se suma dp[i][2^n - 1] 
  a la respuesta. Si el grafo es no dirigido se debe dividir la 
  respuesta entre 2 (con division modular).
  (El caso con n <= 2 es mejor tratarlo aparte).
*/

void solver(){
    int n, m, s, t; cin>>n>>m>>s>>t; 
    s--; t--; // Pasar de 1-index a 0-index
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v; u--; v--; // Pasar de 1-index a 0-index
        graph[u].pb(v);
        graph[v].pb(u); // Comentar si es dirigido
    }

    int lim = 1 << n;
    dp[s][1 << s] = 1;
    for1(mask,lim-1){
        if(!(mask & (1 << s))) continue; // Comentar si no hay fuente especifica
        if(mask & (1 << t) && mask < lim - 1) continue; // Comentar si no hay destino especifico

        for0(i,n){
            if(!(mask & (1 << i))) continue;
            for(int v : graph[i]){
                if(mask & (1 << v)) continue;
                dp[v][mask | (1 << v)] += dp[i][mask];
                dp[v][mask | (1 << v)] %= mod;
            }
        }
    }

    cout<<dp[t][lim - 1]<<endl;
}