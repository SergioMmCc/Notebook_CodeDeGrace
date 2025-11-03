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

const int maxn = 3e5 + 1;
const int LOG = 19; //El logaritmo base 2 del numero maximo de nodos
vector<vector<pii>> tree(maxn), up(maxn, vector<pii>(LOG)); // up[a][i] guarda el ancestro que está a 2^i distancia de a
vector<int> depth(maxn, -1);

void BFS(int s) {
    depth[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int v = pq.top().se;
        pq.pop();
        for(pii e : tree[v]) {
            int u = e.fi, w = e.se;
            if(depth[u] == -1) {
                depth[u] = depth[v] + 1;
                up[u][0] = {v, w};

                for(int j = 1; j < LOG; j++)
                    up[u][j] = {up[up[u][j-1].fi][j-1].fi, min(up[u][j-1].se, up[up[u][j-1].fi][j-1].se)};
                pq.push({depth[u], u});
            }
        }
    }
}

int LCA (int a, int b){
    int mini = 1e9 + 1;
    if(depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    // Este ciclo pone a y b en el mismo nivel
    for(int j = LOG - 1; j >= 0; j--){
        if(k & (1 << j)){
            mini = min(mini, up[a][j].se);
            a = up[a][j].fi;
        }
    }
    if(a == b)
        return mini;
    for(int j = LOG - 1; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            mini = min(mini, up[a][j].se);
            a = up[a][j].fi;
            mini = min(mini, up[b][j].se);
            b = up[b][j].fi;
        }
    }
    return mini;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 1; i < n; i++){
        int u, v, w; cin>>u>>v>>w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
    }

    BFS(1);

    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b;
        cout<<LCA(a, b)<<endl;
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