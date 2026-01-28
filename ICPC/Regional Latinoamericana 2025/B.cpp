#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;

void solver(){
    int n, k; cin>>n>>k;
    vector<vector<int>> dp(min(k+1, n+1), vector<int>(k+1));

    for(int j = 1; j <= k; j++) dp[1][j] = 1;

    for(int i = 2; i <= min(k, n); i++){
        for(int j = 1; j <= k; j++){
            int l = ((i-1)*j + i) / i, r = ((i-1)*j + k) / i;
            dp[i][l] = (dp[i][l] + dp[i-1][j]) % mod;
            if(r < k) dp[i][r+1] = (dp[i][r+1] - dp[i-1][j] + mod) % mod;
        }

        for(int j = 2; j <= k; j++) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
    }

    int ans = 0;
    for(int j = 1; j <= k; j++) ans = (ans + dp[min(k, n)][j]) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}