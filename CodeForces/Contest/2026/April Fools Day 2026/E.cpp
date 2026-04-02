#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 101, inf = 1e9;
int d[maxn][maxn];

void floyd(int n){
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    
    // Inicializar de la siguiente manera:
    // - Si i == j, logicamente la distancia es 0
    // - Si hay una arista entre i y j, la distancia toma ese valor
    // - De lo contrario inicializamos la distancia como infinito
    // Cambiar en caso de grafo dirigido
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
    for(int i = 2; i <= n; i++) cout<<(d[1][i] == inf ? -1 : d[1][i])<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}