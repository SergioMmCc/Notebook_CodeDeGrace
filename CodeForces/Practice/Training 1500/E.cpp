#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int ninf = -1e9;

int calc(int i, int j, int dp[][3], vector<int>& a){
    if(dp[i][j] != -1) return dp[i][j];
    
    if(j == 0){
        dp[i][j] = calc(i - 1, 0, dp, a);
        if(a[i] > dp[i][j]) dp[i][j]++;
        else if(a[i] < dp[i][j]) dp[i][j]--;
    }

    else if(j == 1) dp[i][j] = max(calc(i - 1, 1, dp, a), calc(i - 1, 0, dp, a));

    else{ // j == 2
        dp[i][j] = max(calc(i - 1, 2, dp, a), calc(i - 1, 1, dp, a));
        if(a[i] > dp[i][j]) dp[i][j]++;
        else if(a[i] < dp[i][j]) dp[i][j]--;
    }

    return dp[i][j];
}

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    int dp[n+1][3];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++)
            dp[i][j] = -1;
    }
    dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = ninf;

    int ans = max(calc(n, 1, dp, a), calc(n, 2, dp, a));
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}