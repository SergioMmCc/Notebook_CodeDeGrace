#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

// Estructura para almacenar todas las aristas
struct edge {
    int u, v, w;

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
ll kruskal(vector<edge>& edges, int n){
    ll total = 0;
    sort(edges.begin(), edges.end());
    initDSU(n);

    for(int i = 0; i < edges.sz; i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(find(u) != find(v)){
            total += w;
            join(u, v);
        }
    }

    return total; // Retornar el peso total del MST
}

void solver(){
    int n, m; cin>>n>>m;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        edge newEdge; newEdge.w = w, newEdge.u = u, newEdge.v = v;
        edges.pb(newEdge);
    }

    cout<<kruskal(edges, n)<<endl;
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