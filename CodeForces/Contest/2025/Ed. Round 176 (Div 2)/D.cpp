#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pii;

const ll inf = 4e18; const int maxn = 60;
vector<ll> pot2(maxn); bool visited[maxn][maxn][maxn];
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < maxn; i++) pot2[i] = pot2[i-1] * 2;
}

ll dp[maxn][maxn][maxn];
void fill(){
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            for(int k = 0; k < maxn; k++){
                if(i + j == 0){
                    dp[k][i][j] = 0;
                    visited[k][i][j] = 1;
                }
                else{
                    dp[k][i][j] = inf;
                    visited[k][i][j] = 0;
                }
            }
        }
    }
}

ll calc(int k, int i, int j){
    if(visited[k][i][j]) return dp[k][i][j];
    visited[k][i][j] = 1;

    if(k == 0 && i + j > 0){
        dp[k][i][j] = inf;
        return inf;
    }

    dp[k][i][j] = min(dp[k][i][j], calc(k-1, i, j));
    if(i - k >= 0) dp[k][i][j] = min(dp[k][i][j], calc(k-1, i-k, j) + pot2[k]);
    if(j - k >= 0) dp[k][i][j] = min(dp[k][i][j], calc(k-1, i, j-k) + pot2[k]);

    return dp[k][i][j];
}

void solver(){
    ll x, y; cin>>x>>y;
    ll ans = inf;
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            if(x >> i == y >> j) ans = min(ans, dp[maxn-1][i][j]);
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();

    fill();
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            calc(maxn-1, i, j);
        }
    }

    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}