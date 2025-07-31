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

const int N = 501;
int dp[N][N];

void solver(){
    string s; cin>>s;
    int n = s.sz;
    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;

            dp[i][j] = dp[i+1][j] + 1; // Caso base
            for(int k = i + 1; k <= j; k++){
                if(s[i] != s[k]) continue;

                dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
            }
        }
    }

    cout<<dp[0][n-1];
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