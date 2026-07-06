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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[401][201];

void solver(){
    int n, k; cin>>n>>k;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(all(a));
    vi ps(n+1);
    for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i];

    for(int i = 2; i <= n; i++){
        int lim = i / 2;
        for(int j = 1; j <= lim && j <= k; j++){
            dp[i][j] = dp[i-1][j];
            for(int b = 1; b <= j; b++){
                dp[i][j] = max(dp[i][j], ps[i] - 2*ps[i - b] + ps[i - 2*b] + dp[i - 2*b][j - b]);
            }
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i++) ans = max(ans, dp[i][k]);
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