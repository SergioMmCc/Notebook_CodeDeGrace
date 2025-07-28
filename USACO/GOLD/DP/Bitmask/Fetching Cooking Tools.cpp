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

const int inf = 1e9;

int dist(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void solver(){
    int n; cin>>n;
    vector<pii> a(2*n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se>>a[i+n].fi>>a[i+n].se;

    int lim = 1 << (2*n + 1);
    vector<vector<int>> dp(2*n + 1, vector<int>(lim, inf)); dp[0][1] = 0;

    for(int mask = 0; mask < lim; mask++){
        int dif = 0;
        bool cond = 1;
        for(int i = 1; cond && i <= n; i++){
            if((mask & (1 << i)) && (mask & (1 << (i + n))) == 0) dif++;
            else if((mask & (1 << i)) == 0 && (mask & (1 << (i + n)))) cond = 0;
        }
        if(dif > 2) cond = 0;
        if(!cond) continue;

        for(int i = 0; i <= 2*n; i++){
            if((mask & (1 << i)) == 0) continue;

            int ux = a[i].fi, uy = a[i].se;
            if(dif < 2){ // Puedo coger otra herramienta
                for(int j = 1; j <= n; j++){
                    if((mask & (1 << j))) continue;
                    dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + dist(a[i], a[j]));
                }
            }

            if(dif){ // Quiero entregar una de las que tengo
                for(int j = 1; j <= n; j++){
                    int k = j + n;
                    if((mask & (1 << j)) == 0 || (mask & (1 << k)) == 1) continue;
                    dp[k][mask | (1 << k)] = min(dp[k][mask | (1 << k)], dp[i][mask] + dist(a[i], a[k]));
                }
            }
        }
    }

    int ans = inf;
    for(int i = n+1; i <= 2*n; i++){
        ans = min(ans, dp[i][lim-1] + dist(a[i], a[0]));
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