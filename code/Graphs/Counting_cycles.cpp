#include "../template.h"

/* 
- Complejidad O(2^n * n^2).
- Cuenta la cantidad de ciclos simples (donde el unico 
  vertice que se repite es aquel en el que inicia y termina
  el ciclo) de un grafo no dirigido.
- Puede ser necesario agregar modularidad.
- dp[i][mask] cuenta la cantidad de "simple paths" (que no 
  repiten vertices) que empiezan por el primer bit 
  encendido de 'mask' y terminan en 'i'.
Variantes:
- Para ciclos hamiltonianos revisar el "Counting_paths".
- Si el grafo es dirigido, se arma el grafo normal e inverso.
  En el ciclo para caminos de al menos 2 vertices se usa el 
  inverso. En el ciclo del final se usa el grafo normal, se 
  debe iniciar desde mask=3 y contar los caminos con 2 o mas 
  vertices. No aplica la correccion de aristas multiples con 
  gauss que se menciona abajo. Se elimina la division entre 2 
  del final.
- Si pueden haber aristas multiples y no se deben tener en
  cuenta, guardar con set.
- Si se debe tener en cuenta aristas multiples, sumar a la 
  respuesta 2*gauss(frecuencia de cada arista - 1) (antes de 
  la division del final), para contar los ciclos de tamaño 2 
  (que van de 'u' hacia 'v' en una arista y de 'v' hacia 'u' 
  en otra).
- No cuenta loops. Si hay que contarlos toca sumarlos aparte.
*/

const int maxn = 20;
vector<vi> graph(maxn);

void solver(){
    int n, m; cin>>n>>m;
    for0(i,m){
        int u, v; cin>>u>>v; u--; v--; // Se cambia a 0-index
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int lim = (1 << n);
    vector<vl> dp(n, vl(lim));

    // Cada camino de un solo vertice se puede hacer de una forma
    for0(i,n) dp[i][1 << i] = 1;

    // Cuenta los caminos de al menos 2 vertices
    forlr(mask,3,lim-1){
        for0(i,n){
            // Revisa que 'i' haga parte del camino pero no sea el nodo inicial
            if(!(mask & (1 << i)) || !(mask % (1 << i))) continue;

            // Para cada arista j->i, sumar los que tienen la misma mask, pero sin 'i', y que terminan en 'j'
            for(int j : graph[i]){
                if(!(mask & (1 << j))) continue;
                dp[i][mask] += dp[j][mask ^ (1 << i)];
            }
        }
    }

    // Se suman los caminos de tamaño >= 3 cuyo primer vertice es 'fst' y ultimo 'i' por la cantidad 
    // de aristas de 'i' hacia 'fst'
    ll ans = 0;
    forlr(mask,7,lim-1){
        int cnt =__builtin_popcount(mask), fst = __builtin_ctz(mask);
        if(cnt == 3) continue;
        for0(i,n){
            if(fst == i) continue;
            
            // Si desde i hacia fst hay aristas, entonces se forman ciclos
            ll mul = 0; // Cantidad de aristas de i hacia fst
            for(int v : graph[i]) if(v == fst) mul++;
            ans += mul * dp[i][mask];
        }
    }
    ans /= 2;
    cout<<ans<<endl; // Se divide por 2 ya que los ciclos se contaron en ambas direcciones
}