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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    ll l, h; cin>>l>>h;
    ll x, y, z; cin>>x>>y>>z;
    int c, n, e; cin>>c>>n>>e;
    int total = c + n + e;

    ld ans = 0.0;
    vector<vector<vector<ld>>> dp(c+1, vector<vector<ld>>(n+1, vector<ld> (e+1))); dp[0][0][0] = 1.0;
    for(ll i = 0; i <= c; i++){
        for(ll j = 0; j <= n; j++){
            for(ll k = 0; k <= e; k++){
                int count = i + j + k;
                if(!count) continue;
                ll sum = i*x + j*y + k*z;
                if(sum > h) break;
                if(i && !(sum - x >= l && sum - x <= h)) dp[i][j][k] += dp[i-1][j][k] * (ld)(c - i + 1) / (ld)(total + 1 - count);
                if(j && !(sum - y >= l && sum - y <= h)) dp[i][j][k] += dp[i][j-1][k] * (ld)(n - j + 1) / (ld)(total + 1 - count);
                if(k && !(sum - z >= l && sum - z <= h)) dp[i][j][k] += dp[i][j][k-1] * (ld)(e - k + 1) / (ld)(total + 1 - count);
                ans += (sum >= l ? dp[i][j][k] : 0.0);
            }
        }
    }

    cout<<fixed<<setprecision(8)<<ans<<endl;
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