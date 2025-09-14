#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9 + 7;
const int maxi = 1e6;

vector<ll> pot2(maxi);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < maxi; i++) pot2[i] = (pot2[i-1] * 2) % mod;
}

void solver(){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    int root = 0;
    vector<int> leafs;
    vector<int> prof(n+1); prof[1] = 1;
    queue<pii> q; q.push({1, -1});
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se; q.pop();
        if(u != 1 && tree[u].sz == 1) leafs.pb(u);
        if(u == 1 && tree[u].sz == 2 || tree[u].sz == 3) root = u;
        for(int v : tree[u]){
            if(v == pa) continue;
            q.push({v, u});
            prof[v] = prof[u] + 1;
        }
    }

    if(leafs.sz > 2){
        cout<<0<<endl;
        return;
    }

    if(leafs.sz == 1){
        cout<<pot2[n]<<endl;
        return;
    }

    int res = abs(prof[leafs[0]] - prof[leafs[1]]) + prof[root];

    if(res == prof[root]){
        cout<<pot2[res + 1]<<endl;
        return;
    }

    ll ans = (pot2[res - 1] + pot2[res]) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}