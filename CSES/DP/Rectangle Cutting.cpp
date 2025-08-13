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

void solver(){
    int a, b; cin>>a>>b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9)); 

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }

            // Corte en a
            for(int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            // Corte en b
            for(int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }

    cout<<dp[a][b];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}