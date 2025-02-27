#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5;
vector<vector<int>> tree(maxn);
int dp[maxn][2];

// Un Vertex Cover es un subconjunto de vértices C⊆V tal
// que cada arista del grafo tiene al menos un extremo en C.
// Un minimum vertex cover nos devuelve el tamaño minimo de C
// para que se cumpla esa condicion

// Complejidad:
// Para un grafo cualquiera este es un problema NP - Completo,
// sin embargo, para un arbol o un bipartito, la complejidad 
// es O(n)
void DFS(int n, int parent){
    // 1 quiere decir que el vertice esta en el cover, 0 que no esta
    dp[n][0] = 0; dp[n][1] = 1;
    for(int i : tree[n]){
        if(i == parent) continue;
        DFS(i, n); // Calculamos la respuesta para cada subarbol de n
    }

    // Si n esta en el cover, sus hijos pueden estar o no,
    // mientras que si n no esta en el cover, todos sus 
    // hijos tienen que estar
    for(int i : tree[n]){
        if(i == parent) continue;
        dp[n][0] += dp[i][1];
        dp[n][1] += min(dp[i][0], dp[i][1]);
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(1, -1); // En este caso elegimos 1 como la raiz
    cout<<min(dp[1][0], dp[1][1])<<endl;
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