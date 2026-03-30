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

/*
    Se usa en grafos funcionales o grafos sucesores, que son grafos dirigidos donde 
    cada nodo tiene exactamente una arista de salida, donde estos forman varios 
    componentes (no necesariamente SCC) con exactamente un ciclo y caminos que llevan 
    a ese ciclo.
    Sirve para realizar queries de la forma s, k, en donde se pide deacir a que nodo se 
    llega tras realizar k pasos iniciando en el nodo s.
*/

int LOG_N = 30; // techo del log2 del maximo valor de k que me puedan dar en las queries

// Para cada nodo se calcula a donde llega tras realizar 2^x pasos. Se necesita para usar
// la funcion kSucc.
// Complejidad: O(n * log(k))
void calcSucc(int n, vi& func, vector<vi>& succ){
    for(int i = 1; i <= n; i++) succ[i][0] = func[i];
    for(int bit = 1; bit < LOG_N; bit++){
        for(int i = 1; i <= n; i++){
            succ[i][bit] = succ[succ[i][bit-1]][bit-1];
        }
    }
}

// Retorna el nodo al que se llega tras hacer k pasos partiendo desde s
// Complejidad: O(log(k))
int kSucc(int s, int k, vector<vi>& succ){
    for(int bit = 0; bit < LOG_N; bit++){
        if(k & (1 << bit)) s = succ[s][bit];
    }

    return s;
}

void solver(){
    int n, q; cin>>n>>q;
    vi func(n+1);
    for(int i = 1; i <= n; i++) cin>>func[i];
    vector<vi> succ(n+1, vi(LOG_N));
    calcSucc(n, func, succ);
    while(q--){
        int s, k; cin>>s>>k;
        cout<<kSucc(s, k, succ)<<endl;
    }
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