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
    int n, t, k; cin>>n>>t>>k;
    vii a(n);
    for(int i = 0; i < n; i++) cin>>a[i].se>>a[i].fi;
    sort(all(a));
    for(int i = 0; i < n; i++) swap(a[i].fi, a[i].se);
    // for(int i = 0; i < n; i++) cout<<a[i].fi<<" "<<a[i].se<<endl;

    vi trans(n, -1);
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(a[j].se <= a[i].fi){
                trans[i] = j;
                break;
            }
        }
    }
    // for(int i = 0; i < n; i++) cout<<"i -> "<<i<<" trans -> "<<trans[i]<<endl;

    vector<vi> dp(n, vi(n+1));
    for(int i = 0; i < n; i++){
        dp[i][1] = t - a[i].se + a[i].fi;
        if(i) dp[i][1] = max(dp[i][1], dp[i-1][1]);
    }

    for(int j = 2; j <= n; j++){
        for(int i = 0; i < n; i++){
            if(i) dp[i][j] = dp[i-1][j];

            if(trans[i] != -1){
                dp[i][j] = max(dp[i][j], dp[trans[i]][j-1] - a[i].se + a[i].fi);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] >= k) ans = max(ans, j);
            // cout<<dp[i][j].fi<<' '<<dp[i][j].se<<'\t';
        }
        // cout<<endl;
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