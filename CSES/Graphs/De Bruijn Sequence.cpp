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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<piii> viii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void DFS(int u, int e, vector<viii>& graph, vb& used, vi& ans){
    while(!graph[u].empty()){
        piii edj = graph[u].back();
        int v = edj.fi.fi, add = edj.fi.se, idx = edj.se;
        graph[u].pop_back(); // Eliminar arista ya visitada
        if(used[idx]) continue; // En caso de ya haber visitado esta arista partiendo desde v
        used[idx] = 1;
        DFS(v, add, graph, used, ans);
    }
    ans.pb(e);
}

void solver(){
    int n; cin>>n;
    if(n == 1){
        cout<<10<<endl;
        return;
    }

    vector<viii> graph(1 << (n-1));
    for(int i = 0; i < (1 << (n-1)); i++){
        int num = (i & ((1 << (n-2)) - 1)) << 1;
        graph[i].pb({{num, 0}, 2*i});
        graph[i].pb({{num+1, 1}, 2*i + 1});
    }

    vb used(1 << n);
    vi ans;
    DFS(0, 0, graph, used, ans);
    for(int i = 1; i < n-1; i++) ans.pb(0);
    reverse(all(ans));
    for(int x : ans) cout<<x;
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