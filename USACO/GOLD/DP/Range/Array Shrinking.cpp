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
int dp[N][N], dp2[N];

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        dp[i][i] = a[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            for(int k = i; !dp[i][j] && k < j; k++){
                if(dp[i][k] && dp[i][k] == dp[k+1][j]) dp[i][j] = dp[i][k] + 1;
            }

            // cout<<"i -> "<<i<<" j -> "<<j<<" valor -> "<<dp[i][j]<<endl;
        }
    }

    for(int i = 1; i <= n; i++){
        dp2[i] = N;
        for(int j = i; j; j--){
            if(dp[j][i]) dp2[i] = min(dp2[i], 1 + dp2[j-1]);
        }
    }

    cout<<dp2[n]<<endl;
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