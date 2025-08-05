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
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        dp[i][i] = 1;
        if(i){
            if(a[i] == a[i-1]) dp[i-1][i] = 1;
            else dp[i-1][i] = 2;
        }
    }

    for(int len = 3; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = N;

            for(int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
        }
    }

    cout<<dp[0][n-1]<<endl;
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