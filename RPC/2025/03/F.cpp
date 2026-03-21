#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 1;
vector<vector<int>> g(maxn);
vector<bool> visited(maxn);

ll DFS(int s){
    ll ans = 1;
    for(int v : g[s]){
        if(visited[v]) continue;
        visited[v] = 1;
        ans += DFS(v);
    }

    return ans;
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            ll len = DFS(i);
            ans += (len * (len-1)) / 2;
        }
    }

    cout<<ans - m<<endl;
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