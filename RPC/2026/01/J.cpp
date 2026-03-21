#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((ll)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    ll n, d; ll x, r; cin>>n>>x>>r>>d;
    vi a(n+1), cnt(n+1);
    for(ll i = 1; i <= n; i++){
        cin>>a[i];
        cnt[i] = cnt[i-1];
        if(!a[i]) cnt[i]++;
    }

    vl dp(n+2); dp[n] = x; if(a[n]) dp[n] = min(dp[n], r);
    for(ll i = n-1; i > 0; i--){
        dp[i] = x + dp[i+1];
        dp[i] = min(dp[i], r + dp[min(i+d, n+1)] + x * (cnt[min(i+d-1, n)] - cnt[i-1]) + (a[i] ? 0 : x));
    }

    cout<<dp[1]<<endl;
}

ll main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    ll t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}