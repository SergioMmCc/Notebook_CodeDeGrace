#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 501, inf = 2e9;
int d[maxn][maxn]; // d[i][j] = Longitud de la ruta mas corta desde i hasta j

// Complejidad O(n³)
void floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                // Este if solo es necesario en caso de hayan pesos negativos
                if (d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// Algunas aplicaciones:
//      - Safest Path:
//      Maximizar la probabilidad de sobrevivir por algún camino
//      Los valores son porcentajes
//      d[i][j] = max(d[i][j], d[i][k] * d[k][j]);

void solver(){
    int n, m; cin>>n>>m;
    
    // Inicializar de la siguiente manera:
    // - Si i == j, logicamente la distancia es 0
    // - Si hay una arista entre i y j, la distancia toma ese valor
    // - De lo contrario inicializamos la distancia como infinito
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            d[i][j] = d[j][i] = inf;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        if(d[u][v] > w) d[u][v] = d[v][u] = w;
    }

    floyd(n);
    // Si algun d[i][i] < 0, significa que hay un ciclo negativo
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