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
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<piiii> viiii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<pii>> rmq;

// Llenar sparse table
// O(nlg(n))
void fillRMQ(vi& depth, vi& id){
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

// Halla el valor minimo en el intervalo [l, r]
// O(1)
pii query(int l, int r){
    int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
    return min(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]); // [l, r]
}

// Halla los valores correspondientes de los arrays depth, id y start
void DFS(vector<vi>& tree, int u, int pa, vi& id, vi& depth, vi& start, vi& p){
    start[u] = sz(id); // Marcar en que momento se visito por primera vez
    id.pb(u); // Insertar cuando se visita el nodo por primera vez
    for(int v : tree[u]){
        if(v == pa) continue;
        p[v] = u;
        depth[v] = depth[u] + 1;
        DFS(tree, v, u, id, depth, start, p);
        id.pb(u); // Insertar cada vez que se regresa al nodo
    }
}

// Halla el LCA entre 2 nodos
// O(1)
int LCA(int a, int b, vi& start){
    if(start[a] > start[b]) swap(a, b); // Se asegura que start[a] corresponda a l y start[b] a r
    return query(start[a], start[b]).se;
}

void DFS1(int u, int pa, vector<vi>& tree, viiii& f){
    f[u].fi = {0, u};
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS1(v, u, tree, f);

        pii comp = {f[v].fi.fi + 1, f[v].fi.se};
        if(comp > f[u].se) f[u].se = comp;
        if(f[u].se > f[u].fi) swap(f[u].fi, f[u].se);
    }
}

void DFS2(int u, int pa, vector<vi>& tree, viiii& f, vii& g){
    for(int v : tree[u]){
        if(v == pa) continue;
        g[v] = {1, u};
        g[v] = max(g[v], {g[u].fi + 1, g[u].se});
        
        pii comp = f[u].fi.se == f[v].fi.se ? f[u].se : f[u].fi;
        if(comp.fi) g[v] = max(g[v], {comp.fi + 1, comp.se});

        DFS2(v, u, tree, f, g);
    }
}

int LOG_N = 18; // techo del log2 del maximo valor de k que me puedan dar en las queries

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
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vi depth(n+1), start(n+1), id, pa(n+1);
    viiii f(n+1); 
    vii g(n+1, {-1, -1});
    vector<vi> succ(n+1, vi(LOG_N));

    DFS(tree, 1, 0, id, depth, start, pa); fillRMQ(depth, id);
    DFS1(1, 0, tree, f);
    DFS2(1, 0, tree, f, g);
    calcSucc(n, pa, succ);

    for(int i = 1; i <= n; i++) g[i] = max(f[i].fi, g[i]);

    int q; cin>>q;
    while(q--){
        int u, k; cin>>u>>k;
        int v = g[u].se;

        int w = LCA(u, v, start);
        int dis = depth[u] + depth[v] - 2*depth[w];

        if(dis < k){
            cout<<-1<<endl;
            continue;
        }
        
        if(u == w){
            k = depth[v] - depth[u] - k;
            swap(u, v);
        }
        if(v == w){
            cout<<kSucc(u, k, succ)<<endl;
            continue;
        }

        if(depth[u] - depth[w] < k){
            k -= depth[u] - depth[w];
            swap(u, v);
            k = depth[u] - depth[w] - k;
        }

        cout<<kSucc(u, k, succ)<<endl;
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