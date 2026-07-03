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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int LOG_N = 18; // techo del log2 de n

// Para cada nodo se calcula a donde llega tras realizar 2^x pasos. Se necesita para usar
// la funcion kStep.
// Complejidad: O(n * log(k))
void calc(int n, vi& pa, vector<vi>& up){
    for(int i = 1; i <= n; i++) up[i][0] = pa[i];
    for(int bit = 1; bit < LOG_N; bit++){
        for(int i = 1; i <= n; i++){
            up[i][bit] = up[up[i][bit-1]][bit-1];
        }
    }
}

// Retorna el nodo al que se llega tras hacer k pasos partiendo desde s
// Complejidad: O(log(k))
int kStep(int s, int k, vector<vi>& up, vi& depth){
    if(depth[s] < k) return -1; // Si s tiene menos profundidad que la cantidad de pasos que me piden
    for(int bit = 0; bit < LOG_N; bit++){
        if(k & (1 << bit)) s = up[s][bit];
    }

    return s;
}

void solver(){
    int n, q; cin>>n>>q;
    vi pa(n+1), depth(n+1);
    for(int i = 2; i <= n; i++){
        cin>>pa[i];
        depth[i] = depth[pa[i]] + 1;
    }

    vector<vi> up(n+1, vi(LOG_N));
    calc(n, pa, up);

    while(q--){
        int u, k; cin>>u>>k;
        cout<<kStep(u, k, up, depth)<<endl;
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