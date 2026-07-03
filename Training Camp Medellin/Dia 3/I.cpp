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
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void BFS(int s, vi& save, vii& tree, map<int, bool>& solved, vii& dp){
    queue<int> q; q.push(s);
    solved[save[s]] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        
        int v;

        if(tree[u].fi != -1){
            v = tree[u].fi;
            q.push(v);
            dp[v] = {dp[u].fi, min(dp[u].se, save[u])};
            // cout<<"u -> "<<u<<" v -> "<<v<<" save[v] -> "<<save[v]<<" dp -> {"<<dp[v].fi<<", "<<dp[v].se<<'}'<<endl;
            if(save[v] >= dp[v].fi && save[v] <= dp[v].se) solved[save[v]] = 1;
        }

        if(tree[u].se != -1){
            v = tree[u].se;
            q.push(v);
            dp[v] = {max(dp[u].fi, save[u]), dp[u].se};
            // cout<<"u -> "<<u<<" v -> "<<v<<" save[v] -> "<<save[v]<<" dp -> {"<<dp[v].fi<<", "<<dp[v].se<<'}'<<endl;
            if(save[v] >= dp[v].fi && save[v] <= dp[v].se) solved[save[v]] = 1;
        }
    }
}

void solver(){
    int n; cin>>n;
    map<int, bool> solved;
    vi save(n+1);
    vb pa(n+1);
    vii tree(n+1);
    for(int i = 1; i <= n; i++){
        int u, v;
        cin>>save[i]>>u>>v;
        solved[save[i]] = 0;
        if(u != -1) pa[u] = 1;
        if(v != -1) pa[v] = 1;
        tree[i] = {u, v};
    }

    int s = 0;
    for(int i = 1; i <= n && !s; i++) if(!pa[i]) s = i;

    vii dp(n+1, {0, 1e9+1});
    BFS(s, save, tree, solved, dp);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!solved[save[i]]){
            ans++;
            // cout<<"i -> "<<i<<" save -> "<<save[i]<<endl;
        }
    }
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