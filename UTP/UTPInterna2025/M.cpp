#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

// Estructura para almacenar todas las aristas
struct edge {
    int u, v; ll w;

    // Ordenar las aristas por el menor peso
    bool operator<(const edge& that) const {
        return w < that.w; // Cambiar '<' por '>' para hallar el Maximal Spanning Tree
    }
};

// Implementacion DSU
const int maxn = 10005;
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
    initDSU(n);

    vector<edge> aux;
    for(int i = 0; i < edges.sz; i++){
        int u = edges[i].u, v = edges[i].v; ll w = edges[i].w;
        if(find(u) != find(v)){
            total += w;
            join(u, v);
        }

        else aux.pb(edges[i]);
    }

    if(components > 1) return -1;

    edges = aux;
    return total; // Retornar el peso total del MST
}

void solver(){
    int n, m; cin>>n>>m;
    vector<edge> edges;

    for(int i = 0; i < m; i++){
        int u, v; ll w; cin>>u>>v>>w;

        edge newEdge; newEdge.w = w, newEdge.u = u, newEdge.v = v;
        edges.pb(newEdge);
    }

    sort(edges.begin(), edges.end());
    
    vector<ll> ans;
    ll add = kruskal(edges, n);
    while(add != -1){
        ans.pb(add);
        add = kruskal(edges, n);
    }

    cout<<ans.sz<<endl;
    for(int i : ans) cout<<i<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}