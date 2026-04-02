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

void DFS(int u, vector<vi>& tree, vi& a, vii& calc, vi& step){
    if(tree[u].empty()) calc[u] = {0, 0};
    for(int v : tree[u]){
        DFS(v, tree, a, calc, step);
        pii aux = calc[v];
        if(a[v] == 1) aux.fi++;
        else if(a[v] == 2) aux.se++;

        if(aux <= calc[u]){
            calc[u] = aux;
            step[u] = v;
        }
    }
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 2; i <= n; i++){
        int pa; cin>>pa;
        tree[pa].pb(i);
    }

    vi a(n+1);
    for(int i = 2; i <= n; i++) cin>>a[i];

    vii calc(n+1, {n+1, n+1});
    vi step(n+1);

    DFS(1, tree, a, calc, step);
    int u = 1;
    while(step[u]) u = step[u];
    
    cout<<u<<endl;
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