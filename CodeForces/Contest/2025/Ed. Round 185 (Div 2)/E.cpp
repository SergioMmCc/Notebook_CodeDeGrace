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
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;

void solver(){
    int n, m; cin>>n>>m;
    vi pmax(n+1);
    for(int i = 0; i < m; i++){
        int l, r; cin>>l>>r;
        pmax[r] = max(pmax[r], l);
    }
    for(int i = 1; i <= n; i++) pmax[i] = max(pmax[i], pmax[i-1]);

    vi dp(n+1); dp[1] = 2;
    vi ps(n+1); ps[1] = 2;
    for(int i = 2; i <= n; i++){
        int j = pmax[i-1];
        dp[i] = (ps[i-1] - ps[j] + mod) % mod;
        ps[i] = (ps[i-1] + dp[i]) % mod;
    }
    int ans = (ps[n] - ps[pmax[n]] + mod) % mod;

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