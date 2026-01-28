#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int dp[maxn][2][2];

int calc(int i, int j, int k, vector<bool>& a){
    
    if(dp[i][j][k] != maxn) return dp[i][j][k];

    if(i == 1){
        if(j) return maxn;
        else dp[i][j][k] = 0;
    }
    else if(i == 2){
        if(k) return maxn;
        dp[i][j][k] = calc(1, 0, 1, a);
    }

    else{
        if(j == k){
            dp[i][j][k] = calc(i-1, j, !j, a);
        }
        else{
            dp[i][j][k] = min(calc(i-1, !j, 0, a), calc(i-1, !j, 1, a));
        }
    }

    if(!j && a[i] && dp[i][j][k] != maxn) dp[i][j][k]++;
    return dp[i][j][k];
}

void solver(){
    int n; cin>>n;
    vector<bool> a(n+1);
    for(int i = 1; i <= n; i++){
        int save; cin>>save;
        a[i] = save ? 1 : 0;
    }

    if(n == 1){
        cout<<a[1] ? 1 : 0;
        cout<<endl;
        return;
    }

    // Limpiar dp
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = maxn;
            }
        }
    }

    if(a[1]) dp[1][0][0] = 1;
    else dp[1][0][0] = 0;
    int ans = min(calc(n, 0, 0, a), calc(n, 1, 1, a));
    ans = min(ans, calc(n, 0, 1, a));
    ans = min(ans, calc(n, 1, 0, a));

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < 2; j++){
    //         for(int k = 0; k < 2; k++){
    //             cout<<"i -> "<<i<<" j -> "<<j<<" k -> "<<k<<" dp -> ";
    //             if(dp[i][j][k] == maxn) cout<<'/'<<endl;
    //             else cout<<dp[i][j][k]<<endl;
    //         }
    //     }
    // }

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