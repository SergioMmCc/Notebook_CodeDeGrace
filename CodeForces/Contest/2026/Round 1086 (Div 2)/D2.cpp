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

vii ans;
vector<vi> graph(8000);
vector<vb> care(8000, vb(8000));
vb called(8000);

void DFS(int u, int n, vi& orden, vs& a){
    called[u] = 1;
    care[u][u] = 1;
    for(int v : orden){
        if(!care[u][v] && a[u][v] == '1'){
            ans.pb({u, v});
            if(!called[v]) DFS(v, n, orden, a);
            for(int w : graph[v]) care[u][w] = 1;
        }
    }
}

bool BFS(int s, int n, vs& a, vector<vi>& tree){
    vb vis(n); vis[s] = 1;
    queue<int> q; q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

    for(int i = 0; i < n; i++) if((vis[i] && a[s][i] == '0') || (!vis[i] && a[s][i] == '1')) return 0;
    return 1;
}

int BFS2(int n){
    vector<vi> tree(n);
    for(pii x : ans){
        tree[x.fi].pb(x.se);
        tree[x.se].pb(x.fi);
    }
    queue<int> q; q.push(0);
    vb vis(n); vis[0] = 1;
    int cnt = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            cnt++;
            q.push(v);
        }
    }

    return cnt;
}

void solver(){
    int n; cin>>n;

    for(int i = 0; i < n; i++){
        called[i] = 0;
        graph[i].clear();
        for(int j = 0; j < n; j++){
            care[i][j] = 0;
        }
    }

    vs a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vb ind(n);
    vi outd(n);
    for(int i = 0; i < n; i++){
        if(a[i][i] == '0'){
            cout<<"No"<<endl;
            return;
        }

        for(int j = 0; j < n; j++){
            if(i == j || a[i][j] == '0') continue;
            if(a[j][i] == '1'){
                cout<<"No"<<endl;
                return;
            }

            ind[j] = 1;
            outd[i]++;
            graph[i].pb(j);
        }
    }

    vector<vi> aux(n);
    for(int i = 0; i < n; i++){
        aux[outd[i]].pb(i);
    }

    vi orden;
    for(int i = n-1; i >= 0; i--){
        for(int j : aux[i]){
            orden.pb(j);
        }
    }

    for(int i = 0; i < n; i++){
        if(!ind[i]) DFS(i, n, orden, a);
    }

    if(sz(ans) != n-1){
        cout<<"No"<<endl;
        return;
    }

    vb vis(n);
    for(pii x : ans) vis[x.fi] = 1, vis[x.se] = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout<<"No"<<endl;
            return;
        }
    }

    int machetazo = BFS2(n);
    if(machetazo != n){
        cout<<"No"<<endl;
        return;
    }

    vector<vi> tree(n);
    for(pii x : ans) tree[x.fi].pb(x.se);

    for(int i = 0; i < n; i++){
        if(!BFS(i, n, a, tree)){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
    for(pii x : ans) cout<<x.fi+1<<' '<<x.se+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        ans.clear();
        solver();
    }

    return 0;
}