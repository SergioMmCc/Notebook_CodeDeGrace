#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int top=1e5, big=500, MOD=1e9+7;
long long dp[big+7][top+7];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s;
    cin>>n>>s;

    dp[0][0] = 1;
    int k=big;

    for(int i=0; i<n; i++){ // paso linea
        for(int j=0; j<=k; j++){ // salto
            if(i+1 >= n || s[i+1] != '#'){
                dp[j][i+1] += dp[j][i]; // no salto
                dp[j][i+1] %= MOD; 
            }

            if(i+j+2 >= n || s[i+j+2] != '#'){
                int p=i+j+2;
                if(p > n) p = n;
                dp[j+1][p] += dp[j][i]; // salto
                dp[j+1][p] %= MOD;
            }
        }
    }

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<=2*k; j++){
            cout<<dp[i][j]<<" ";
        }cout<<"\n";
    }
    */

    long long ans=0;
    for(int j=0; j<=k; j++){
        ans += dp[j][n];
        ans %= MOD;
    }
    cout<<ans<<"\n";
}