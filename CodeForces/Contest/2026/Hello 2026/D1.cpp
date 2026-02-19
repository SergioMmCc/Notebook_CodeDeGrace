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

int BFS(int n, vector<vi>& tree){
    queue<int> q; q.push(1);
    vb vis(n+1); vis[1] = 1;
    vi sons(n+1), lev(n+1), cntLev(n+1);
    int ans = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            sons[u]++;
            ans = max(ans, sons[u]);

            lev[v] = lev[u] + 1;
            ans = max(ans, cntLev[lev[v]]);
            cntLev[lev[v]]++;
            
            vis[v] = 1;
            q.push(v);
        }
    }

    return ans + 1;
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    cout<<BFS(n, tree)<<endl;
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