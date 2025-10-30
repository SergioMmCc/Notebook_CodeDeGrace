#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int inf = 2e9 + 2;

// Estructura para almacenar todas las aristas
struct edge {
    int u, v, w;

    // Ordenar las aristas por el menor peso
    bool operator<(const edge& that) const {
        return w < that.w; // Cambiar '<' por '>' para hallar el Maximal Spanning Tree
    }
};

// Implementacion DSU
const int maxn = 1005;
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
int kruskal(vector<edge>& edges, int n){
    int ans = inf;
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.sz; i++){
        initDSU(n);
        int mine = 1e9, maxe = -1e9;
        for(int j = i; components != 1 && j < edges.sz; j++){
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if(find(u) != find(v)){
                mine = min(mine, w);
                maxe = max(maxe, w);
                join(u, v);
            }
        }

        if(components != 1) break;
        ans = min(ans, maxe - mine);
    }

    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        edge newEdge; newEdge.w = w, newEdge.u = u, newEdge.v = v;
        edges.pb(newEdge);
    }

    int ans = kruskal(edges, n);
    if(ans == inf) cout<<"NO"<<endl;
    else cout<<"YES"<<endl<<ans<<endl;
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