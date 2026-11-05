#include "../template.h"

/*
DP con optimizacion de Knuth, pasa de O(n^3) a O(n^2).
- Es un caso especial de DP en rangos, se aplica en 
  transiciones de la forma:
  * dp[l][r] = C[l][r] + min(dp[l][i] + dp[i+1][r]), 
  * con l <= i < r.
  * 'C' es una funcion de costos.
CONDICION:
- Sea opt[l][r] el menor valor de 'i' que minimiza 
  dp[l][r], se debe cumplir que: 
  opt[l][r-1] <= opt[l][r] <= opt[l+1][r].
- Dicha condicion se cumple cuando la funcion de costo
  'C' satisface que para todo a <= b <= c <= d:
  * C[b][c] <= C[a][d].
  * C[a][c] + C[b][d] <= C[a][d] + C[b][c].
- Sin embargo usualmente no se hace la demostracion 
  sino que se intuye o compara contra una solucion 
  O(n^3) en un caso pequeño.
  
- 0-index.
MAXIMIZAR
- Para toda la tabla C hacer C[i][j] *= -1. Esta tabla 
  'C' negada es la que debe cumplir las condiciones.
- Al resultado final tambien hacerle *= -1.
*/

const int maxn = 1e3 + 5;
ll dp[maxn][maxn], C[maxn][maxn];
int opt[maxn][maxn];

void solver(){
    int n; cin>>n;
    
    // LEER O PRECALCULAR C
    
    for0(i,n) dp[i][i] = 0, opt[i][i] = i; // Rangos de tamaño 1
    
    forlr(len,2,n){
        forlr(l,0,n-len){
            int r = l+len-1;
            dp[l][r] = INFL;
            int lo = opt[l][r-1], hi = min(opt[l+1][r], r-1);
            forlr(i,lo,hi){
                ll cur = dp[l][i] + dp[i+1][r];
                if(cur < dp[l][r]){
                    dp[l][r] = cur;
                    opt[l][r] = i;
                }
            }
            dp[l][r] += C[l][r];
        }
    }
    cout<<dp[0][n-1]<<endl;
}
}
