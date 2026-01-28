#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 2;
vector<vector<int>> tree(maxn);
vector<int> group0, group1;
vector<bool> group(maxn);

void DFS(int s, int prev){
    group[s] = !group[prev];
    group[s] ? group1.pb(s) : group0.pb(s);
    for(int to : tree[s]){
        if(to == prev) continue;
        DFS(to, s);
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    DFS(1, n+1);
    ll ans = 0;
    for(int u : group0) ans += group1.sz - tree[u].sz;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}