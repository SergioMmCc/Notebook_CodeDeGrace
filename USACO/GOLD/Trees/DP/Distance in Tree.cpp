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

ll ans = 0;

void DFS(int k, int u, int pa, vector<vi>& tree, vector<vi>& dp){
    dp[u][0] = 1;
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(k, v, u, tree, dp);

        for(int i = 1; i <= k; i++) dp[u][i] += dp[v][i-1];
    }

    ans += 2 * dp[u][k];

    for(int i = 0; i < k - 1; i++){
        for(int v : tree[u]){
            if(v == pa) continue;

            ans += dp[v][i] * (dp[u][k - i - 1] - dp[v][k - i - 2]);
        }
    }
}

void solver(){
    int n, k; cin>>n>>k;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vector<vi> dp(n+1, vi(k+1));

    DFS(k, 1, 0, tree, dp);

    cout<<(ans >> 1)<<endl;
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