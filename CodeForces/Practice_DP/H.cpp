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

void solver(){
    int n; cin>>n;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++){
        for(int l = 1, r = i - 1; l <= r && r > 2; l++, r--){
            dp[i][r] += dp[l][min(l, r - 2)];
        }

        for(int j = 1; j <= i; j++) dp[i][j] += dp[i][j-1];
        dp[i][i]++;
    }

    cout<<dp[n][n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("peacefulsets.in", "r", stdin);
	freopen("peacefulsets.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}