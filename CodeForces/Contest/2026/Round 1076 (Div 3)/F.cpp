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

void solver(){
    int n; cin>>n;
    pii a, b;
    cin>>a.fi>>a.se>>b.fi>>b.se;
    ll ans = b.fi - a.fi; 

    vii c(n);
    for(int i = 0; i < n; i++) cin>>c[i].fi;
    for(int i = 0; i < n; i++) cin>>c[i].se;

    sort(all(c));

    map<int, int> d;
    int aux = 0;
    vii e; // miny, maxy
    for(int i = 0; i < n; i++){
        int x = c[i].fi;
        if(d.find(x) == d.end()){
            d[x] = aux;
            aux++;
            e.pb({c[i].se, c[i].se});
        }
        e[sz(e) - 1] = {min(e[sz(e) - 1].fi, c[i].se), max(e[sz(e) - 1].se, c[i].se)};
    }

    vector<pair<ll, ll>> dp(sz(e));
    dp[0] = {abs(a.se - e[0].se) + e[0].se - e[0].fi, abs(a.se - e[0].fi) + e[0].se - e[0].fi};

    for(int i = 1; i < sz(e); i++){
        dp[i].fi = min(dp[i-1].fi + abs(e[i].se - e[i-1].fi), dp[i-1].se + abs(e[i].se - e[i-1].se)) + e[i].se - e[i].fi;
        dp[i].se = min(dp[i-1].fi + abs(e[i].fi - e[i-1].fi), dp[i-1].se + abs(e[i].fi - e[i-1].se)) + e[i].se - e[i].fi;
    }

    ll add = min(dp[sz(e) - 1].fi + abs(b.se - e[sz(e)-1].fi), dp[sz(e)-1].se + abs(b.se - e[sz(e)-1].se));
    ans += add;
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