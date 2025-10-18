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
    vector<vector<int>> mat(8, vector<int>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> dp(8, vector<int>(8));
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            if(i == 7 && !j) continue;
            dp[i][j] = 1e8;
            if(i < 7 && j) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            if(i < 7) dp[i][j] = min(dp[i][j], dp[i+1][j]);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);

            dp[i][j] += mat[i][j];
        }
    }

    cout<<dp[0][7]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("king2.in", "r", stdin);
	freopen("king2.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}