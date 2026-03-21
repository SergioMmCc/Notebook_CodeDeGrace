#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ld = long double;

ld dp[1005][10005];

void solver(){
    int n, k; cin>>n>>k;
    vector<ld> a(k+1), prefixMult(k+1); a[0] = 1.0; prefixMult[0] = 1.0;
    for(int j = 1; j <= k; j++){
        cin>>a[j];
        prefixMult[j] = prefixMult[j-1] * a[j];
        dp[1][j] = prefixMult[j-1] * (1 - a[j]);
    }
    ld ans = prefixMult[k];
    for(int i = 2; i <= n; i++){
        ld t = 0;
        for(int j = 1; j <= k; j++){
            t = t * a[j-1] + dp[i-1][j];
            dp[i][j] = t * (1 - a[j]);
        }
        t = t * a[k];
        ans = max(ans, t);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
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