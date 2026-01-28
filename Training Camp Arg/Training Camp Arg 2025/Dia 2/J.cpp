#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
// typedef pair<short, short> pii;

short dp[101][101][10001]; // MLE

void solver(){
    short n, total = 0; cin>>n;
    for(int k = 0; k <= n; k++){
        for(int j = 0; j <= n; j++){
            for(int i = 0; i <= 10000; i++){
                dp[k][j][i] = -1;
            }
        }
    }
    vector<short> a(n+1), b(n+1);
    for(short i = 1; i <= n; i++){
        cin>>a[i]>>b[i];
        total += b[i];
    }

    vector<float> ans(n+1);
    // Algun problema aqui 
    for(short j = 1; j <= n; j++){
        for(short i = 1; i <= 10000; i++){
            dp[1][j][i] = dp[1][j-1][i];
            if(i - a[j] == 0) dp[1][j][i] = max(dp[1][j][i], b[j]);
            if(dp[1][j][i] != -1){
                float tt = total, dpp = dp[1][j][i];
                float sum = (tt + dpp) / 2.0;
                float lim = i;
                ans[1] = max(ans[1], min(lim, sum));
            }
        }
    }
    for(short k = 2; k <= n; k++){
        for(short j = 1; j <= n; j++){
            for(short i = 1; i <= 10000; i++){
                dp[k][j][i] = max(dp[k-1][j][i], dp[k][j-1][i]);
                if(i - a[j] >= 0 && dp[k-1][j-1][i-a[j]] != -1) dp[k][j][i] = max((int)dp[k][j][i], (int)dp[k-1][j-1][i-a[j]] + b[j]);

                if(dp[k][j][i] != -1) ans[k] = max(ans[k], min((float)i, (float)((float)(dp[k][j][i] + total) / 2.0)));
            }
        }
    }

    // for(short i = 1; i <= 22; i++){
    //     for(short j = 1; j <= 3; j++){
    //         cout<<"i -> "<<i<<" j -> "<<j<<" dp -> "<<dp[1][j][i]<<endl;
    //     }
    // }

    // if(ans[1] == 99.0 && n == 100){
    //     for(int i = n; i >= 0; i--) cout<<a[i]<<' '<<b[i]<<endl;
    //     return;
    // }
    for(short k = 1; k <= n; k++){
        cout<<fixed<<setprecision(10)<<ans[k]<<' ';
    }
    cout<<endl;
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