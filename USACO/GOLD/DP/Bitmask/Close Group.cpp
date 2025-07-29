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

const int maxn = 18, inf = 20;
bool e[maxn][maxn];

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v; u--; v--;
        e[u][v] = e[v][u] = 1;
    }

    int lim = 1 << n;
    vector<int> dp(lim, inf); dp[0] = 0;

    // Calcular los subconjuntos que cumplen la condicion
    for(int mask = 1; mask < lim; mask++){
        int st = -1;
        for(int i = 0; st == -1 && i < n; i++){
            if(mask & (1 << i)) st = i;
        }
        if(dp[mask ^ (1 << st)] == inf) continue;

        bool cond = 1;
        for(int i = st + 1; cond && i < n; i++){
            if((mask & (1 << i)) && !e[st][i]) cond = 0;
        }
        if(cond) dp[mask] = 1;
    }

    for(int mask = 0; mask < lim; mask++){
        for(int submask = mask; submask != 0; submask = (submask - 1) & mask){
            int subset = mask ^ submask;
            dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
        }
    }

    cout<<dp[lim - 1]<<endl;
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