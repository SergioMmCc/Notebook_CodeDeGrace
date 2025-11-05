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
vector<vector<int>> dp(maxn, vector<int>(2));

void DFS(int u, int pa){
    for(int v : tree[u]){
        if(v == pa) continue;
        DFS(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    for(int v : tree[u]){
        if(v == pa) continue;
        dp[u][1] = max(dp[u][1], 1 + dp[v][0] + dp[u][0] - max(dp[v][0], dp[v][1]));
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(1, -1);
    cout<<max(dp[1][0], dp[1][1])<<endl;
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