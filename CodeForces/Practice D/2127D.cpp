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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 1;
const ll mod = 1e9 + 7;
vector<ll> fact(maxn);
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * (ll)i) % mod;
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vector<int>> tree(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    if(m != n - 1){
        cout<<0<<endl;
        return;
    }

    vector<int> a(n+1);
    for(int u = 1; u <= n; u++){
        for(int v : tree[u]){
            if(tree[v].sz == 1) a[u]++;
        }
    }
    
    vector<vector<int>> sons(n+1);
    queue<pii> q; q.push({1, -1});
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se; q.pop();
        for(int v : tree[u]){
            if(v == pa) continue;
            sons[u].pb(v);
            q.push({v, u});
        }
    }

    for(int u = 1; u <= n; u++){
        int count = 0;
        for(int v : tree[u]){
            if(tree[v].sz > 1) count++;
        }
        if(count >= 3){
            cout<<0<<endl;
            return;
        }
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == n-1){
            cout<<(2 * fact[a[i]]) % mod<<endl;
            return;
        }
        ans = (ans * fact[a[i]]) % mod;
    }

    ans = (4 * ans) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcFact();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}