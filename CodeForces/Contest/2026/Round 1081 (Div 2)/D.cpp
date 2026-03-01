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

void DFS(int u, int pa, vl& ans, vector<vi>& tree, vl& val, vl& sum, vl& sumNorm, vl& bc, vi& depth){

    int cnts = 0;
    int best = 0;
    multiset<int> bestD;
    for(int v : tree[u]){
        if(v == pa) continue;
        cnts++;
        DFS(v, u, ans, tree, val, sum, sumNorm, bc, depth);

        if(sumNorm[v] > sumNorm[best]) best = v;
        sum[u] += sum[v];
        sumNorm[u] += sumNorm[v];
        depth[u] = max(depth[u], depth[v]);
        bestD.insert(depth[v]);
    }

    depth[u]++;
    sum[u] += val[u];
    sumNorm[u] += val[u];

    if(cnts == 1) bc[u] = bc[best];
    else if(cnts > 1){
        for(int v : tree[u]){
            if(v == pa) continue;
            int aux = depth[v];
            auto it = bestD.find(aux);
            bestD.erase(it);

            ll d = *(bestD.rbegin());
            bc[u] = max(max(bc[v], bc[u]), d * sumNorm[v]);
            bestD.insert(aux);
        }
    }

    ans[u] = sum[u] + bc[u] - val[u];
    sum[u] += sumNorm[u] - val[u];
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    vl a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vl ans(n+1), dp(n+1), sum(n+1), sumNorm(n+1), bc(n+1);
    vi depth(n+1);
    DFS(1, -1, ans, tree, a, sum , sumNorm, bc, depth);


    // cout<<"val -> \t\t"; for(int i = 1;i <= n; i++) cout<<a[i]<<'\t'; cout<<endl;
    // cout<<"sum -> \t\t"; for(int i = 1;i <= n; i++) cout<<sum[i]<<'\t'; cout<<endl;
    // cout<<"sumNorm -> \t"; for(int i = 1;i <= n; i++) cout<<sumNorm[i]<<'\t'; cout<<endl;
    // cout<<"bc -> \t\t"; for(int i = 1;i <= n; i++) cout<<bc[i]<<'\t'; cout<<endl;
    // cout<<"ans -> \t\t"; for(int i = 1;i <= n; i++) cout<<ans[i]<<'\t'; cout<<endl;


    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
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