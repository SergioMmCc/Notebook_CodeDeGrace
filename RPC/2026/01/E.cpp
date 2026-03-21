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

struct edge {
    int u, v; ll w;

    // Ordenar las aristas por el menor peso
    bool operator<(const edge& that) const {
        return w < that.w; // Cambiar '<' por '>' para hallar el Maximal Spanning Tree
    }
};

// Implementacion DSU
const int maxn = 200005;
int components;
vector<int> leader(maxn), sizen(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(leaderU != leaderV){
        if(sizen[leaderV] > sizen[leaderU])
            swap(leaderU, leaderV);
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        components--;
    }
}

// Algoritmo de Kruskal para hallar el Minimal Spanning Tree
// Complejidad O(m * lg(m))
// En grafos densos m ≈ n²
ll kruskal(vector<edge>& edges, int n){
    ll total = 0;
    sort(edges.begin(), edges.end());
    initDSU(n);

    for(int i = 0; i < sz(edges); i++){
        int u = edges[i].u, v = edges[i].v; ll w = edges[i].w;
        if(find(u) != find(v)){
            total += w;
            join(u, v);
        }
    }

    return total; // Retornar el peso total del MST
}

void solver(){
    int n, m, r; cin>>n>>m>>r;
    vector<edge> edges(m+r);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        edges[i] = {u, v, 0LL};
    }
    for(int i = 0; i < r; i++){
        int u, v; ll w; cin>>u>>v>>w;
        edges[i+m] = {u, v, w};
    }

    cout<<kruskal(edges, n)<<endl;
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