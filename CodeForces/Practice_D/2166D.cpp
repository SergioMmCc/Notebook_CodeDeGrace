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

const ll mod = 998244353;

void solver(){
    int n; cin>>n;
    vector<ll> freq(n);
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        freq[num-1]++;
    }

    sort(all(freq));

    vector<ll> dp(n+1);
    for(int i = 0; i < n; i++){
        ll cnt = freq[i];
        for(ll j = n; j > cnt; j--){
            dp[j] += cnt * dp[j - cnt];
            dp[j] %= mod;
        }

        dp[cnt] += cnt;
        dp[cnt] %= mod;
    }

    ll ans = 0;
    for(int i = freq[n-1]; i <= n; i++) ans = (ans + dp[i]) % mod;
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