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
    int n, k; cin>>n>>k; k &= 1;
    vl a(n+1), b(n+1), ps(n+1), smps(n+1), ss(n+1), pmss(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i];
    smps[n] = ps[n]; for(int i = n-1; i >= 0; i--) smps[i] = max(smps[i+1], ps[i]);
    ss[n] = a[n]; for(int i = n-1; i >= 0; i--) ss[i] = ss[i+1] + a[i];
    pmss[0] = ss[0]; for(int i = 1; i <= n; i++) pmss[i] = max(pmss[i-1], ss[i]);

    ll ans = -1e18;
    for(int i = 1; i <= n; i++) ans = max(ans, smps[i] - ps[i-1] + pmss[i] - ss[i] + (k ? b[i] : 0));
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