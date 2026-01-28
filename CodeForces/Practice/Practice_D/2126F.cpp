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
typedef pair<int, ll> pil;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 1;
vector<vector<pil>> tree(maxn);

void BFS(int n, vector<pil>& pa, vector<int>& c, vector<map<int, ll>>& sum){
    queue<int> q; q.push(1);
    vector<bool> vis(n+1); vis[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(pil e : tree[u]){
            int v = e.fi; ll w = e.se;
            if(vis[v]) continue;
            sum[u][c[v]] += w;
            pa[v] = {u, w};
            q.push(v);
            vis[v] = 1;
        }
    }
}

ll op(int u, int c, vector<map<int, ll>>& sum){
    if(sum[u].find(c) == sum[u].end()) return 0;
    return sum[u][c];
}

void solver(){
    int n, q; cin>>n>>q;
    for(int i = 1; i <= n; i++) tree[i].clear();

    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin>>c[i];

    vector<map<int, ll>> sum(n+1);

    ll total = 0;
    for(int i = 1; i < n; i++){
        int u, v; ll w; cin>>u>>v>>w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
        if(c[u] != c[v]) total += w;
    }

    vector<pil> pa(n+1);
    BFS(n, pa, c, sum);

    while(q--){
        int u, nuevo; cin>>u>>nuevo;
        int actual = c[u];
        c[u] = nuevo;
        total += op(u, actual, sum) - op(u, nuevo, sum);
        if(u > 1){
            int v = pa[u].fi; ll w = pa[u].se;
            if(c[v] == actual) total += w;
            if(c[v] == nuevo) total -= w;

            sum[v][actual] -= w;
            sum[v][nuevo] += w;
        }

        cout<<total<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}