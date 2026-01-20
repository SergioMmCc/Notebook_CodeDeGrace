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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<vi> dp(n+1, vi(n+1, n));
    vi mini(n+1, n);
    for(int i = 1; i <= n; i++){
        dp[i][0] = i;
        for(int j = 1; j <= min(n, a[i]); j++){
            dp[i][j] = min(mini[j], dp[i][j-1]) + (j == a[i] ? 0 : 1);
        }

        mini[n] = dp[i][n];
        for(int k = n-1; k >= 0; k--) mini[k] = min(mini[k+1], dp[i][k]);
    }

    int ans = n;
    for(int j = 0; j <= n; j++) ans = min(ans, dp[n][j]);
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