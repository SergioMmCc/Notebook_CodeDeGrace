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
    int n, m; cin>>n>>m;
    vi fst(m+1, n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        maxx = max(maxx, num);
        fst[num] = min(fst[num], i+1);
    }
    for(int i = maxx - 1; i >= 1; i--) fst[i] = min(fst[i], fst[i+1]);

    vector<vi> dp(m+1, vi(maxx+1));
    int ans = 0;
    for(int i = 1; i <= maxx; i++){
        for(int j = i; j <= m; j++){
            dp[j][i] = dp[j-1][i];
            int lim = min(i-1, j-i);
            for(int k = 0; k <= lim; k++){
                dp[j][i] = max(dp[j][i], dp[j-i][k] + (i-k) * (n - fst[i] + 1));
            }
            ans = max(ans, dp[j][i]);
        }
    }

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