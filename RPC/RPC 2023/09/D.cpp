#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 300005;
int dp[maxn][2][2][2][3];

int calc(vector<int>& arr, int i, int a, int b, int c, int d){
    if(!i) return 0;
    if(dp[i][a][b][c][d] != -1) return dp[i][a][b][c][d];

    dp[i][a][b][c][d] = calc(arr, i-1, a, b, c, d);
    if(a){
        dp[i][a][b][c][d] = max(dp[i][a][b][c][d], calc(arr, i-1, 0, b, c, 0));
    }
    if(b){
        dp[i][a][b][c][d] = max(dp[i][a][b][c][d], calc(arr, i-1, a, 0, c, 1));
    }
    if(c){
        dp[i][a][b][c][d] = max(dp[i][a][b][c][d], calc(arr, i-1, a, b, 0, 2));
    }

    if(arr[i] == d){
        if(d == 0 && !a) dp[i][a][b][c][d]++;
        else if(d == 1 && !b) dp[i][a][b][c][d]++;
        else if(d == 2 && !c) dp[i][a][b][c][d]++;
    }

    return dp[i][a][b][c][d];
}

void solver(){
    int n; cin>>n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin>>arr[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    for(int m = 0; m < 3; m++){
                        dp[i][j][k][l][m] = -1;
                    }
                }
            }
        }
    }

    int ans = 0;
    ans = max(ans, calc(arr, n, 0, 0, 0, 0));
    ans = max(ans, calc(arr, n, 0, 0, 0, 1));
    ans = max(ans, calc(arr, n, 0, 0, 0, 2));

    ans = max(ans, calc(arr, n, 1, 0, 0, 1));
    ans = max(ans, calc(arr, n, 1, 0, 0, 2));
    ans = max(ans, calc(arr, n, 0, 1, 0, 0));
    ans = max(ans, calc(arr, n, 0, 1, 0, 2));
    ans = max(ans, calc(arr, n, 0, 0, 1, 0));
    ans = max(ans, calc(arr, n, 0, 0, 1, 1));

    ans = max(ans, calc(arr, n, 1, 1, 0, 2));
    ans = max(ans, calc(arr, n, 1, 0, 1, 1));
    ans = max(ans, calc(arr, n, 0, 1, 1, 0));

    cout<<ans<<endl;
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