#include "../template.h"

/*
- Complejidad O(2^n * n^2).
- Se asume que se da la entrada en 1-index y se pasa a 0-index.
- Halla el minimo peso para recorrer todos los vertices del grafo
  iniciando en el vertice 'start' (teniendo en cuenta que para moverse 
  entre 2 vertices solo se pueden usar aristas entre ellos).

- Otras aplicaciones:
- Para hallar el camino hamiltoniano de menos costo (empezando en 
  cualquier vertice) se inicializa el DP con dp[i][1<<i] = 0, para 
  'i' entre 0 y n-1.
- Para pedir que termine en algun vertice en especifico 'u' se hace que 
  la unica mascara valida que contenga 'u' sea lim-1 (con 'lim' = 1<<n), 
  y que solo sea valida cuando el vertice final sea 'u', es decir, 
  dp[u][lim-1].
- Para hallar el ciclo hamiltoniano mas corto, podemos elegir el vertice
  0 como inicial, marcar dp[0][1] = 0 e inicializar los demas estados en
  INFL, despues corremos el algoritmo con normalidad y finalmente para
  cada 1 <= i < n calculamos dp[i][lim-1] + dis(i, 0) (tener en cuenta 
  que si el grafo es dirigido, el peso de ir desde 'i' hacia 0 se guardo 
  al reves) y elegimos el menor.
*/

typedef pair<ll, int> pli;
const int maxn = 20;
vector<vector<pli>> graph(maxn);

void solver(){
    int n, m, start; cin>>n>>m>>start; start--;
    for0(i,m){ // Si el grafo es dirigido, guardar solo la arista inversa
        int u, v, w; cin>>u>>v>>w; u--; v--; // Pasar a 0-index
        graph[u].pb({w, v});
        graph[v].pb({w, u});
    }

    // Inicializar el dp
    int lim = 1 << n;
    vector<vl> dp(n, vl(lim, INFL));
    dp[start][1 << start] = 0; // Poner distancia 0 en el camino que solo tiene 'start'

    for1(mask,lim-1){
        if(!(mask & (1 << start))) continue; // Si en ese camino no se ha visitado 'start'
        for0(u,n){ // Camino finalizando en u
            if(!(mask & (1 << u))) continue;

            for(pli e : graph[u]){
                int v = e.se; ll w = e.fi; // Yendo de 'v' hacia 'u'
                if(!(mask & (1 << v))) continue;
                dp[u][mask] = min(dp[u][mask], w + dp[v][mask ^ (1 << u)]);
            }
        }
    }

    ll ans = INFL;
    for0(i,n) ans = min(ans, dp[i][lim - 1]); // Compara el terminar en cada posible nodo
    cout<<(ans == INFL ? -1 : ans)<<endl; // Imprime -1 si no existe el recorrido
}