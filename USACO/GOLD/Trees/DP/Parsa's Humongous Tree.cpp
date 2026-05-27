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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void DFS(int u, int pa, vector<vi>& tree, vll& a, vll& dp){
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(v, u, tree, a, dp);

        dp[u].fi += max(abs(a[u].fi - a[v].fi) + dp[v].fi, abs(a[u].fi - a[v].se) + dp[v].se);
        dp[u].se += max(abs(a[u].se - a[v].fi) + dp[v].fi, abs(a[u].se - a[v].se) + dp[v].se);
    }
}

void solver(){
    int n; cin>>n;
    vll a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vll dp(n+1);
    DFS(1, 0, tree, a, dp);
    cout<<max(dp[1].fi, dp[1].se)<<endl;
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