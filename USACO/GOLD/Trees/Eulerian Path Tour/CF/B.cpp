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

const int maxn = 3e5 + 1;
vector<vector<int>> tree(maxn);
vector<bool> marked(maxn);

int diameter(int n){
    queue<int> q; q.push(1);
    vector<bool> vis(n+1); vis[1] = 1;
    vector<int> dis(n+1);
    pii maxi = {0, 1};
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            dis[v] = dis[u] + 1;
            maxi = max(maxi, {dis[v], v});
        }
    }

    marked[maxi.se] = 1;
    return maxi.se;
}

int BFS(int n, int s){
    vector<bool> vis(n+1); vis[s] = 1;
    vector<int> dis(n+1);
    queue<int> q; q.push(s);
    int maxx = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            dis[v] = dis[u] + 1;
            maxx = max(maxx, dis[v]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(dis[i] == maxx){
            marked[i] = 1;
            s = i;
        }
        vis[i] = 0;
        dis[i] = 0;
    }

    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            dis[v] = dis[u] + 1;
            if(dis[v] == maxx) marked[v] = 1;
        }
    }

    return maxx;
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    int s = diameter(n);
    int maxx = BFS(n, s);
    for(int i = 1; i <= n; i++) cout<<(marked[i] ? maxx + 1 : maxx)<<endl;
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