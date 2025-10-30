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
    int u, v, w, id;

    // Ordenar las aristas por el menor peso
    bool operator<(const edge& that) const {
        return w < that.w; // Cambiar '<' por '>' para hallar el Maximal Spanning Tree
    }
};

// Implementacion DSU
const int maxn = 50005;
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
int kruskal(vector<edge>& edges, int n, int m, ll s, vector<int>& deletedEdges){
    vector<bool> used(m+1);
    sort(edges.begin(), edges.end());
    initDSU(n);

    for(int i = edges.sz - 1; components > 1 && i >= 0; i--){
        int u = edges[i].u, v = edges[i].v;
        if(find(u) != find(v)){
            join(u, v);
            used[edges[i].id] = 1;
        }
    }

    int count = 0;
    for(int i = 0; i < edges.sz; i++){
        if(used[edges[i].id]) continue;
        int w = edges[i].w;
        if(w > s) break;
        s -= w;
        count++;
        deletedEdges.pb(edges[i].id);
    }

    return count;
}

void solver(){
    int n, m; ll s; cin>>n>>m>>s;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        edge newEdge; newEdge.w = w, newEdge.u = u, newEdge.v = v, newEdge.id = i + 1;
        edges.pb(newEdge);
    }

    vector<int> deletedEdges;
    cout<<kruskal(edges, n, m, s, deletedEdges)<<endl;
    sort(deletedEdges.begin(), deletedEdges.end());
    for(int i = 0; i < deletedEdges.sz; i++){
        if(i) cout<<' ';
        cout<<deletedEdges[i];
    }
    cout<<endl;
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