#include "../template.h"

/*
- Complejidad O(n³)
- Sirve tanto para grafos dirigidos como no dirigidos
- Esta implementación es 1-index
- Aplicacion afest Path:
  Se quiere maximizar la probabilidad de sobrevivir por algún camino
  y los valores son porcentajes.
  d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
*/

const int maxn = 501;
int d[maxn][maxn]; // d[i][j] = Longitud de la ruta mas corta desde i hasta j

void floyd(int n){
    for1(k,n){
        for1(i,n){
            for1(j,n){
                // Este if solo es necesario en caso de hayan pesos negativos
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    
    // Inicializar de la siguiente manera:
    // - Si i == j, la distancia es 0
    // - Si hay una arista entre i y j, la distancia toma ese valor
    // - De lo contrario inicializamos la distancia como infinito
    for1(i,n-1){
        forlr(j,i+1,n){
            d[i][j] = d[j][i] = INF;
        }
    }
    for0(i,m){
        int u, v, w; cin>>u>>v>>w;
        if(d[u][v] > w) d[u][v] = d[v][u] = w; // Cambiar en caso de grafo dirigido
    }

    floyd(n); // Si algun d[i][i] < 0, significa que hay un ciclo negativo
}