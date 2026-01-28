#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define up upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> pli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 1e18;

void solver(){
    int n, k; cin>>n>>k;
    vector<pli> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].fi;
        a[i].se = i;
    }

    if(k >= n){
        for(int i = 0; i < n; i++) cout<<a[i].fi<<' '; cout<<endl;
        return;
    }

    sort(all(a));

    vector<vector<ll>> dis(n, vector<ll>(n));
    for(int i = n-1; i > 0; i--){
        ll sum = 0;
        for(int j = i - 1; j >= 0; j--){
            sum += (a[i].fi - a[j].fi) * (a[i].fi - a[j].fi);
            dis[i][j] = sum;
        }
    }

    vector<vector<pli>> dp(k+1, vector<pli>(n, {inf, -1}));
    for(int i = 0; i < n; i++){
        dp[1][i] = {dis[i][0], -1};
    }

    for(int j = 2; j <= k; j++){
        for(int i = 0; i < n; i++){
            for(int m = i - 1; m >= 0; m--){
                dp[j][i] = min(dp[j][i], {dp[j-1][m].fi + dis[i][m+1], m});
            }
        }
    }

    vector<ll> c;
    int idx = k, u = n-1;
    while(idx){
        c.pb(a[u].fi);
        u = dp[idx][u].se;
        idx--;
    }

    int j = k - 1;
    vector<ll> ans(n);
    for(int i = 0; i < n; i++){
        if(c[j] < a[i].fi) j--;
        ans[a[i].se] = c[j];
    }

    for(int i = 0; i < n; i++) cout<<ans[i]<<' '; cout<<endl;
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