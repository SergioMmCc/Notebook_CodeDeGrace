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

const int mod = 1e9 + 7, maxn = 301;

int dp[301][301][301];

int sum(int a, int b){
    return (a + b) % mod;
}

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    // Limpiar
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = 0;
            }
        }
    }

    int ans = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j][k] = sum(dp[i][j][k], dp[i-1][j][k]);
                if(a[i] >= j){
                    dp[i][a[i]][k] = sum(dp[i][a[i]][k], dp[i-1][j][k]);
                    // cout<<"here1"<<" i -> "<<i<<" a[i] -> "<<a[i]<<" j -> "<<j<<" k -> "<<k<<" b -> "<<b<<" add -> "<<add<<endl;
                    // dp[i][a[i]][j][b] = sum(dp[i][a[i]][j][b], dp[i-1][j][k][b]);
                }
                else if(a[i] >= k){
                    // cout<<"here2"<<endl;
                    dp[i][j][a[i]] = sum(dp[i][j][a[i]], dp[i-1][j][k]);
                }
            }
        }
    }

    for(int j = 0; j <= n; j++){
        for(int k = 0; k <= j; k++){
            // cout<<"j -> "<<j<<" k -> "<<k<<" val -> "<<dp[n][j][k]<<endl;
            ans = sum(ans, dp[n][j][k]);
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}