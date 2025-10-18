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

const int maxn = 2e5 + 1;
vector<vector<pii>> graph(maxn);

bool check(int n, int k, vector<int>& b){
    vector<bool> can(n+1); can[1] = 1;
    vector<int> maxi(n+1);

    for(int i = 1; i <= n; i++){
        if(!can[i]) continue;
        
        maxi[i] = min(maxi[i] + b[i], k);
        for(pii edge : graph[i]){
            int j = edge.fi, w = edge.se;
            if(maxi[i] < w) continue;

            can[j] = 1;
            maxi[j] = min(k, max(maxi[j], maxi[i]));
        }
    }

    return can[n];
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i++) graph[i].clear();

    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin>>b[i];
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u].pb({v, w});
    }

    // Binary Search
    int l = 1, r = 1e9, ans = -1;
    while(l <= r){
        int k = (l + r) / 2;
        if(check(n, k, b)){
            ans = k;
            r = k - 1;
        }
        else l = k + 1;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}