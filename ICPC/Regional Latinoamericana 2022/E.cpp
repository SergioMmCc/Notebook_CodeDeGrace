#include <bits/stdc++.h>

using namespace std; 
int n, k, e; 

const int oo = 1e9; 
const int maxi = 7; 

int memo[1002][1002][maxi+2]; 
int dp(int i, int a, int b) {
    
    if(a < 0) return oo;
    if(b < 0) return oo;

    if(i == k) return dp(i+1, a, b);

    if(i >= n) return a + b;

    if(memo[i][a][b] != -1) return memo[i][a][b];

    int left = dp(i+1, a-i, b); 
    int right = dp(i+1, a, b-i); 
    int none = dp(i+1, a, b);

    return memo[i][a][b] = min({left, right, none});
}

int main() {
    cin >> n >> k >> e; 
    memset(memo, -1, sizeof memo);

    if(e > maxi && n-e-k > maxi){
         cout << 0 << endl;
         return 0; 
    }

    cout << dp(1, max(e, n-e-k), min(e, n-e-k)) << endl;

}