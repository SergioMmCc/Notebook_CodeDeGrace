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

void solver(){
    int n, k; cin>>n>>k;
    if(!k){
        cout<<0<<endl;
        return;
    }
    int cnt = 0;
    vector<bool> b(30);
    for(int i = 0; i < 30; i++){
        if(n & (1 << i)){
            b[i] = 1;
            cnt++;
        }
    }

    if(k > 30 - cnt){
        cout<<cnt + k - 1<<endl;
        return;
    }

    vector<vector<vector<int>>> dp(30, vector<vector<int>>(k+1, vector<int>(2)));

    if(b[0]) for(int j = 1; j <= k; j++) dp[0][j][1] = 1;
    if(!b[0] && k >= 2) for(int j = 2; j <= k; j++) dp[0][j][1] = 1;

    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = max(dp[i-1][j][1], dp[i-1][j][0]);
            if(j) dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);

            if(j) dp[i][j][1] = dp[i][j-1][1];

            if(!b[i]){
                if(dp[i-1][j-1][1] > 0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1] + 1);
                if(j > 1) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-2][0] + 1);
            }
            else{
                if(j) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + 1);
                if(dp[i-1][j][1] > 0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + 1);
            }
        }
    }

    cout<<max(dp[29][k][0], dp[29][k][1])<<endl;
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