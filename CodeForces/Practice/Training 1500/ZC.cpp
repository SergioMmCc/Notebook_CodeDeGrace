#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int inf = 1e9;

int calc(vector<int>& a, int dp[], int n, int s){
    if(s > n+1) return inf;
    if(dp[s] != inf) return dp[s];
    dp[s] = min(calc(a, dp, n, a[s]), 1 + calc(a, dp, n, s + 1));
    return dp[s];
}

void solver(){
    int n; cin>>n;
    vector<int>a(n+1);
    int dp[n + 2]; dp[n+1] = 0, dp[n] = 1;
    for(int i = 0; i < n; i++) dp[i] = inf;
    for(int i = 1; i <= n; i++){
        int save; cin>>save;
        save += i + 1;
        a[i] = save;
    }
    cout<<calc(a, dp, n, 1)<<endl;
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