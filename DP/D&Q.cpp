#include "../template.h"

/*
DP con divide and conquer optimization.
- Para dp de la forma dp[i][j] = min(dp[i-1][m-1] + C[m][j]), donde:
  * 1 <= i <= k
  * 0 <= j <= n
  * 1 <= m <= j
  * C[m][j] es una funcion de costo evaluable rapidamente.
- La interpretacion tipica (pero no unica) es que se quieren partir 
  los elementos en grupos, entonces dp[i][j] es el minimo costo de 
  partir los primeros 'j' elementos en exactamente 'i' grupos no 
  vacios, donde el ultimo grupo es [m...j] y C[m][j] es el costo de 
  este grupo.
- COMPLEJIDAD se reduce de O(k*n*n) a O(k*n*log(n)). 
  (Mas la complejidad de hallar la funcion de costo).
- Para poder usarlo se requiere que:
  sea opt(i,j) el valor de 'm' que minimiza dp[i][j], 
  opt(i,j) <= opt(i,j+1) para todo par i,j.
- Esa restriccion se garantiza si C cumple la desigualdad del 
  cuadrilatero:
  para a <= b <= c <= d, C(a,c) + C(b,d) <= C(a,d) + C(b,c).
  Sin embargo usualmente no se hace la demostracion sino que se
  intuye o compara contra una solucion O(k*n*n) en un caso pequeño.
  Una forma de reformular esta desigualdad es:
  cuando se incrementa el punto 'r' del rango, decrementar el punto 
  'l' hace que sea mas costoso. Formalmente:
  para todo l<=r, C(l−1,r) - C(l,r) <= C(l−1,r+1) - C(l,r+1).
MAXIMIZAR:
- Si en lugar de minimizar se quiere maximizar:
  * if(aux > best) best = aux, opt = m;
  * Se cambian los INFL por -INFL.
  * 'C' ahora deberia estar compuesta por pesos negativos.

APLICACIONES:
- Tipico en problemas de partir un arreglo en 'k' segmentos 
  minimizando la suma de costos como suma de cuadrados, distancia
  a la mediana, distancia a una particion.
*/

const int maxn = 1e3 + 1, maxk = 20 + 1;
ll C[maxn][maxn]; // se quita si se puede hallar facil para cada m,j
ll dp[maxk][maxn];

void compute(int k, int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = (l+r) >> 1, opt = -1, best = INF;
    for(int m = optl; m <= min(mid, optr); m++){
        int aux = dp[k-1][m-1] + C[m][mid];
        if(aux < best) best = aux, opt = m; // Desempata el menor m 
    }
    dp[k][mid] = best;
    compute(k, l,     mid-1, optl, opt);  // j menores: opt a la izquierda
    compute(k, mid+1, r,     opt,  optr); // j mayores: opt a la derecha
}

void solver(){
    int n, k; cin>>n>>k;
    for1(m,n) forlr(j,m,n) cin>>C[m][j];

    for0(j,n+1) dp[0][j] = INFL; // No se pueden partir en 0 grupos
    dp[0][0] = 0; // 0 elementos si se pueden partir en 0 grupos
    for1(i,k){ // Hallar el dp para 'i' grupos
        for0(j,n+1) dp[i][j] = INFL; // Inicializar en INFL
        compute(i, i, n, i, n);
    }
    
    cout<<dp[k][n]<<endl;
}
