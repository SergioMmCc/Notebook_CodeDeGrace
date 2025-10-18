#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;

int sum(int a, int b){
    return (((a + b) % mod) + mod) % mod;
}

void solver(){
    int n, m, d; cin>>n>>m>>d; d *= d;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin>>mat[i];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));

    // Primer nivel
    for(int j = 0; j < m; j++){
        if(mat[n-1][j] == 'X') dp[n-1][j][0] = 1;
    }
    for(int j = 0, l = 0, r = 0, count = 0; j < m; j++){
        while(r < m && (r - j) * (r - j) <= d){
            count = sum(count, dp[n-1][r][0]);
            r++;
        }
        while(l < m && (j - l) * (j - l) > d){
            count = sum(count, -dp[n-1][l][0]);
            l++;
        }

        if(mat[n-1][j] == 'X') dp[n-1][j][1] = sum(count, -dp[n-1][j][0]);
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0, l = 0, r = 0, count = 0; j < m; j++){
            while(r < m && 1 + (r - j) * (r - j) <= d){
                count = sum(count, sum(dp[i+1][r][0], dp[i+1][r][1]));
                r++;
            }
            while(l < m && 1 + (j - l) * (j - l) > d){
                count = sum(count, -sum(dp[i+1][l][0], dp[i+1][l][1]));
                l++;
            }

            if(mat[i][j] == 'X') dp[i][j][0] = count;
        }

        for(int j = 0, l = 0, r = 0, count = 0; j < m; j++){
            while(r < m && (r - j) * (r - j) <= d){
                count = sum(count, dp[i][r][0]);
                r++;
            }
            while(l < m && (j - l) * (j - l) > d){
                count = sum(count, -dp[i][l][0]);
                l++;
            }

            if(mat[i][j] == 'X') dp[i][j][1] = sum(count, -dp[i][j][0]);
        }
    }

    int ans = 0;
    for(int j = 0; j < m; j++) ans = sum(ans, sum(dp[0][j][0], dp[0][j][1]));
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}