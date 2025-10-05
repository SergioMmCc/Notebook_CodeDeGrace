#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, m; cin>>n>>m;
    vector<vector<int>> a(m+1), b(m+1);

    int idx = 0;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        if(!num){
            idx++;
            continue;
        }
        
        if(num < 0) b[idx].pb(-num);
        else a[idx].pb(num);
    }

    for(int i = 1; i <= m; i++){
        sort(all(a[i]));
        sort(all(b[i]));
    }

    vector<vector<int>> dp(m+1, vector<int>(m+1));
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            if(j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);

            auto it1 = upper_bound(all(a[i]), j);
            auto it2 = upper_bound(all(b[i]), i - j);

            int index1 = it1 - a[i].begin();
            int index2 = it2 - b[i].begin();

            dp[i][j] += index1 + index2;
        }
    }

    int ans = 0;
    for(int j = 0; j <= m; j++) ans = max(ans, dp[m][j]);
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