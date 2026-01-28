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

void solver(){
    int n, m; cin>>n>>m;
    vector<int> inDegree(n);
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v; u--; v--;
        inDegree[v]++;
        graph[u].pb(v);
    }

    // Calcular
    int ans = 0;
    vector<int> dp(n);
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!inDegree[i]){
            q.push(i);
            dp[i] = 0;
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--;
            dp[v] = max(dp[v], dp[u] + 1);
            if(inDegree[v]) continue;

            q.push(v);
            ans = max(ans, dp[v]);
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("longpath.in", "r", stdin);
	freopen("longpath.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}