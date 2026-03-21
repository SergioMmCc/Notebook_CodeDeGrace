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

int BFS(int n, vii& edj){
    vector<vi> tree(n);
    for(pii x : edj){
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
    vs a(n);
    vi cnt(n);
    queue<int> q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i][j] == '1') cnt[i]++;
        }
        if(!cnt[i]) q.push(i);
    }
    
    // Probar casos obvios de imposibilidad
    for(int i = 0; i < n; i++){
        if(a[i][i] == '0'){
            cout<<"No"<<endl;
            return;
        }
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i][j] == 1 && a[j][i] == '1'){
                cout<<"No"<<endl;
                return;
            }
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                if(a[i][j] == '1' && a[j][k] == '1' && a[i][k] == '0'){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }

    vii ans;
    while(!q.empty()){
        int v = q.front(); q.pop();
        // cout<<"v -> "<<v<<endl;
        for(int u = 0; u < n; u++){
            if(a[u][v] == '0' || u == v) continue;

            bool cond = 1;
            for(int j = 0; cond && j < n; j++){
                if(a[u][j] == '0' || j == u || j == v) continue;
                if(a[j][v] == '1'){
                    cond = 0;
                    cnt[u]--;
                }
            }
            if(cond){
                ans.pb({u, v});
                cnt[u]--;
                if(!cnt[u]) q.push(u);
                // a[u][v] = '0';
            }
        }
    }

    if(sz(ans) != n-1){
        cout<<"No"<<endl;
        return;
    }

    vb vis(n);
    for(pii x : ans){
        vis[x.fi] = 1;
        vis[x.se] = 1;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout<<"No"<<endl;
            return;
        }
    }

    int machetazo = BFS(n, ans);
    if(machetazo != n){
        cout<<"No"<<endl;
        return;
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
        solver();
    }

    return 0;
}