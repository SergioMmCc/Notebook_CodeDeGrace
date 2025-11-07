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
vector<ll> f(maxn), len(maxn);
int n;

void DFS1(int u, int pa = -1){
    len[u] = 1;
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS1(v, u);
        f[u] += f[v];
        len[u] += len[v];
    }

    f[u] += len[u];
}

void DFS2(int u, int pa = -1){
    if(pa != -1) f[u] = n + f[pa] - 2*len[u];
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS2(v, u);
    }
}

void solver(){
    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS1(1);
    DFS2(1);

    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout<<ans<<endl;
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