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

const ll inf = 1e17;

ll c3(ll a, ll b, ll c){
    return min(abs(a - b) + abs(a - c), min(abs(b - a) + abs(b - c), abs(c - a) + abs(c - b)));
}

ll c2(ll a, ll b){
    return abs(a - b);
}

ll calcDP(int n, vector<ll>& a){
    vector<vector<ll>> dp(n, vector<ll>(2, inf));
    dp[2][1] = c3(a[0], a[1], a[2]);
    dp[1][0] = c2(a[0], a[1]);

    for(int i = 3; i < n; i++){
        dp[i][1] = c3(a[i], a[i-1], a[i-2]) + min(dp[i-3][0], dp[i-3][1]);
        dp[i][0] = c2(a[i], a[i-1]) + min(dp[i-2][1], dp[i-2][0]);
    }

    return min(dp[n-1][0], dp[n-1][1]);
}

void solver(){
    int n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll ans = calcDP(n, a);

    // Rotar 1 vez
    vector<ll> b(n);
    for(int i = 1; i < n; i++) b[i] = a[i-1];
    b[0] = a[n-1];
    ans = min(ans, calcDP(n, b));

    // Rotar 2 vez
    vector<ll> c(n);
    for(int i = 1; i < n; i++) c[i] = b[i-1];
    c[0] = b[n-1];
    ans = min(ans, calcDP(n, c));

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