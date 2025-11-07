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
vector<pii> f(maxn);
vector<int> g(maxn), h(maxn), ans(maxn);

void DFS1(int u, int pa = -1){
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS1(v, u);
        if(f[v].fi + 1 > f[u].fi){
            h[u] = f[u].fi;
            f[u] = {f[v].fi + 1, v};
        }
        else if(f[v].fi + 1 > h[u]) h[u] = f[v].fi + 1;
    }
}

void DFS2(int u, int pa = -1){
    if(pa != -1){
        if(f[pa].se == u) g[u] = h[pa] + 1;
        else g[u] = f[pa].fi + 1;
        g[u] = max(g[u], g[pa] + 1);
    }

    ans[u] = max(g[u], f[u].fi);

    for(int v : tree[u]){
        if(v == pa) continue;
        DFS2(v, u);
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS1(1);
    DFS2(1);
    for(int i = 1; i <= n; i++) cout<<ans[i]<<' '; cout<<endl;
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