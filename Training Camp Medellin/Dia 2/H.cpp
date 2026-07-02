#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef vector<int> vi;

const int inf = 1e9;

int dp[5001][2501][2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i <= 5000; i++){
        for(int j = 0; j <= 2500; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = inf;
            }
        }
    }

    int n; cin>>n;
    vi a(n+2);
    for(int i = 1;i <= n; i++) cin>>a[i];

    int k = (n + 1) / 2;
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[1][1][1] = max(0, a[2] - a[1] + 1);
    vi ans(k+1, inf); ans[1] = dp[1][1][1];

    for(int i = 2; i <= n; i++){
        int lim = (i+1) / 2;
        dp[i][0][0] = 0;
        for(int j = 1; j <= lim; j++){
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]);

            dp[i][j][1] = min(dp[i-2][j-1][1] + max(0, min(a[i-1], a[i-2] - 1) - a[i] + 1), 
                              dp[i-2][j-1][0] + max(0, a[i-1] - a[i] + 1)) + max(0, a[i+1] - a[i] + 1);


            ans[j] = min(ans[j], min(dp[i][j][0], dp[i][j][1]));
        }
    }

    for(int i = 1; i <= k; i++) cout<<ans[i]<<' ';
    cout<<endl;

    return 0;
}