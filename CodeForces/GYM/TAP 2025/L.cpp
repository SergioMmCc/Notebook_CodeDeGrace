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

const int maxn = 1e5 + 1, rmaxn = 450;
vector<vector<ll>> dp(rmaxn, vector<ll>(maxn));

void solver(){
    int n; ll g; cin>>n>>g;
    vector<ll> ps(n+1);
    for(int i = 1; i <= n; i++){
        ll save; cin>>save;
        ps[i] = ps[i-1] + save;
    }

    ll ans = 0;
    for(int i = 1; i < rmaxn; i++){
        for(int j = (i * i + i) / 2; j <= n; j++){
            dp[i][j] = max(dp[i][j-1], g + dp[i-1][j-i] - ps[j] + ps[j-i]);
            ans = max(dp[i][j], ans);
        }
    }

    cout<<ans<<endl;
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