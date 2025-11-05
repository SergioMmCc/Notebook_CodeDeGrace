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
vector<vector<int>> tree(maxn), up(maxn, vector<int>(LOG)); // up[a][i] guarda el ancestro que está a 2^i distancia de a
vector<int> depth(maxn, -1);

void BFS(int s) {
    depth[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int v = pq.top().se;
        pq.pop();
        for(int u : tree[v]) {
            if(depth[u] == -1) {
                depth[u] = depth[v] + 1;
                up[u][0] = v;

                for(int j = 1; j < LOG; j++) 
                    up[u][j] = up[up[u][j-1]][j-1];
                pq.push({depth[u], u});
            }
        }
    }
}

int LCA (int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    // Este ciclo pone a y b en el mismo nivel
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j))
            a = up[a][j];
    }
    if(a == b)
        return a;
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(1);

    int q; cin>>q;
    while(q--){
        int a, b, c; cin>>a>>b>>c;
        int k = LCA(a, b);
        if(depth[a] + depth[b] - 2 * depth[k] <= c){
            cout<<b<<endl;
            continue;
        }

        if(depth[a] - depth[k] == c){
            cout<<k<<endl;
            continue;
        }

        if(depth[a] - depth[k] < c){
            c -= depth[a] - depth[k];
            swap(a, b);
            c = depth[a] - depth[k] - c;
        }

        for(int j = 0; j < LOG; j++){
            if(c & (1 << j)){
                a = up[a][j];
            }
        }

        cout<<a<<endl;
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