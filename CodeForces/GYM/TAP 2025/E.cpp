#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 2e5 + 1;
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

int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    // Este ciclo pone a y b en el mismo nivel
    for(int j = LOG - 1; j >= 0; j--){
        if(k & (1 << j))
            a = up[a][j];
    }
    if(a == b)
        return a;
    for(int j = LOG - 1; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

// Valor por nivel y ramas
vector<ll> a(maxn);
vector<int> rama(maxn);
map<pii, ll> sum;
map<pii, int> wLCA;
ll ans1 = 0;
int ans2 = maxn;

void DFS(int u, int pa){
    if(u == 1){
        for(int v : tree[u]){
            rama[v] = v;
            sum[{depth[v], rama[v]}] += (ll)a[v];
            ans1 = max(ans1, sum[{depth[v], rama[v]}]);
            DFS(v, u);
        }
        return;
    }

    for(int v : tree[u]){
        if(v == pa) continue;
        rama[v] = rama[u];
        sum[{depth[v], rama[v]}] += (ll)a[v];
        ans1 = max(ans1, sum[{depth[v], rama[v]}]);
        DFS(v, u);
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 2; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(1);
    DFS(1, -1);

    for(int i = 2; i <= n; i++){
        if(!a[i]) continue;
        pii test = {depth[i], rama[i]};
        if(sum[test] == ans1){
            if(wLCA.find(test) != wLCA.end()){
                int aux = LCA(wLCA[test], i);
                // cout<<"i -> "<<i<<" antes -> "<<wLCA[test]<<" aux -> "<<aux<<endl;
                wLCA[test] = aux;
            }
            else wLCA[test] = i;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = i; j <= n; j++){
    //         cout<<"LCA entre "<<i<<" y "<<j<<" es "<<LCA(i, j)<<endl;
    //     }
    // }

    for(auto x : wLCA){
        int u = x.se, v = x.fi.fi;
        // cout<<"depthV -> "<<v<<" LCA -> "<<u<<" depthLCA -> "<<depth[u]<<endl;
        ans2 = min(ans2, v - depth[u] + 1);
    }

    cout<<ans1<<' '<<ans2<<endl;
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