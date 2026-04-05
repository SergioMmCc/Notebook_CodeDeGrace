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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e7;

void DFS(int u, int pa, int& k, vector<vi>& tree, vii& dp){
    if(sz(tree[u]) == 1){
        dp[u] = {0, inf};
        return;
    }

    for(int v : tree[u]){
        if(v == pa) continue;

        DFS(v, u, k, tree, dp);
        if(dp[v].fi + 1 < dp[u].fi){
            dp[u].se = dp[u].fi;
            dp[u].fi = dp[v].fi + 1;

            dp[u].se = min(dp[u].se, dp[v].se + 1);
        }
        else dp[u].se = min(dp[u].se, dp[v].fi + 1);
    }

    if(dp[u].fi + dp[u].se <= k+1) dp[u] = {0, inf};
}

void solver(){
    int n, k, r; cin>>n>>k>>r;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vii dp(n+1, {inf, inf});

    DFS(r, -1, k, tree, dp);

    cout<<(!dp[r].fi ? "YES" : "NO")<<endl;
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