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

const int maxn = 20;
vector<vector<int>> graph(maxn);

// Complejidad O(2 ^ n * n ^ 2)
void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v; u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int lim = (1 << n);
    vector<vector<ll>> dp(n, vector<ll>(lim));

    // Contamos los "simple path" que contiene el grafo que 
    // empiezan por el primer bit encendido de la mascara y 
    // terminan en i

    // Cada camino de 1 vertice se puede hacer de una forma
    for(int i = 0; i < n; i++) dp[i][1 << i] = 1;

    // Si i no es el primer vertice activado y hay arista j -> i
    // sumamos lo que hubiera en el subconjunto mask, quitando a i
    // y que terminaba en j
    for(int mask = 3; mask < lim; mask++){
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i)) || !(mask % (1 << i))) continue;
            
            for(int j : graph[i]){
                if(!(mask & (1 << j))) continue;
                dp[i][mask] += dp[j][mask ^ (1 << i)];
            }
        }
    }

    // Para cada mask cuyo primer vertice sea fst y ultimo vertice i
    // sumamos dp[mask][i] a la respuesta si existe arista i -> fst
    // ya que esta es la que cerraria el ciclo
    ll ans = 0;
    for(int mask = 7; mask < lim; mask++){
        for(int i = 0; i < n; i++){
            int count = 0, fst = n;
            for(int j = 0; j < n; j++){
                if(mask & (1 << j)){
                    count++;
                    fst = min(fst, j);
                }
            }
            if(count < 3 || fst == i) continue;
            
            bool cond = 0;
            for(int v : graph[i]){
                if(v == fst) cond = 1;
            }
            if(cond) ans += dp[i][mask];
        }
    }
    ans /= 2;
    // Dividimos la respuesta por 2 ya que los ciclos estan siendo considerados en ambas direcciones
    cout<<ans<<endl;
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