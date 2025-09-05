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

void solver(){
    int n; cin>>n;
    vector<ll> a(n+1), ps(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ps[i] = ps[i-1] + a[i];
        dp[i][i] = a[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            dp[i][j] = max(a[i] + ps[j] - ps[i] - dp[i+1][j], a[j] + ps[j-1] - ps[i-1] - dp[i][j-1]);
        }
    }
    
    cout<<dp[1][n]<<endl;
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