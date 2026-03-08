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

void DFS(int s, int pa, vector<vi>& tree, vi& dp){
    for(int v : tree[s]){
        if(v == pa) continue;
        DFS(v, s, tree, dp);
        dp[s] = min(dp[s], min(dp[v], v));
    }
}

int BFS(int s, int n, vector<vi>& tree){
    vb vis(n+1); vis[s] = 1; vis[1] = 1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

    int ans = 0;
    for(int i = 2; !ans && i <= n; i++){
        if(!vis[i]) ans = i-1;
    }

    return ans == 0 ? n : ans;
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vi dp(n+1, n+1);
    DFS(1, -1, tree, dp);
    for(int v : tree[1]){
        if(dp[v] == 2 || v == 2){
            dp[1] = BFS(v, n, tree);
            break;
        }
    }

    cout<<dp[1];
    for(int i = 2; i <= n; i++) cout<<' '<<dp[i]-1;
    cout<<endl;
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