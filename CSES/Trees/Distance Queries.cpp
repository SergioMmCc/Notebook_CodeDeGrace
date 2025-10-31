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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 1;
vector<vector<int>> tree(maxn);
vector<int> id, depth(maxn), start(maxn);
vector<vector<pii>> rmq;

// Llenar sparse table
void fillRMQ(){
    int n = sz(id); rmq.resize(n);
    int lgn = 31 - __builtin_clz(n);

    for(int i = 0; i < n; i++){
        rmq[i].resize(lgn + 1);
        rmq[i][0] = {depth[id[i]], id[i]};
    }

    for(int j = 1; j <= lgn; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
}

pii query(int l, int r){
    int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
    return min(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]); // [l, r]
}

void DFS(int u, int pa){
    start[u] = sz(id); // Antes de la insercion para que sea 0-index como la Sparse Table
    id.pb(u);
    for(int v : tree[u]){
        if(v == pa) continue;
        depth[v] = depth[u] + 1;
        DFS(v, u);
        id.pb(u); // Insertar cada vez que se regresa al nodo
    }
}

int LCA(int a, int b){
    if(start[a] > start[b]) swap(a, b);
    return query(start[a], start[b]).se;
}

void solver(){
    int n, q; cin>>n>>q;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v; u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(0, -1);
    fillRMQ();

    while(q--){
        int u, v; cin>>u>>v; u--; v--;
        cout<<depth[u] + depth[v] - 2 * depth[LCA(u, v)]<<endl;
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