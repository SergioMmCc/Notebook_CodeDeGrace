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

ll calc(int n, vl& a, vll& dp){
    ll ans = a[n-1];
    dp[n-1] = {a[n-1] - (a[n-1] & 1), a[n-1] - ((a[n-1] + 1) & 1)};

    for(int i = n-2; i >= 0; i--){
        if(a[i] > 1){
            dp[i].fi = dp[i+1].fi + a[i] - (a[i] & 1);

        }
        ans = max(ans, a[i] + max(dp[i+1].fi, dp[i+1].se));
        dp[i].se = a[i] - ((a[i] + 1) & 1) + max(dp[i+1].fi, dp[i+1].se);
    }

    for(int i = 0; i < n; i++) ans = max(ans, max(dp[i].fi, dp[i].se));
    return ans;
}

void solver(){
    int n; cin>>n; n--;
    vl a(n);
    vll dp1(n), dp2(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll ans = calc(n, a, dp1);
    reverse(all(a));
    ans = max(ans, calc(n, a, dp2));

    for(int i = 1; i < n; i++){
        int inv = n - i;
        ans = max(ans, max(dp1[i].fi, dp1[i].se) + max(dp2[inv].fi, dp2[inv].se));
        // if(a[i] & 1) ans = max(ans, dp1[i].fi + dp2[inv].se) + 1;
    }

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