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
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n)); dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = -1e8;
            if(j < i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            dp[i][j] += a[i][j];
        }
    }

    int ans = -1e8;
    for(int j = 0; j < n; j++) ans = max(ans, dp[n-1][j]);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("slalom.in", "r", stdin);
	// freopen("slalom.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}