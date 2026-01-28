#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

ll testNumber(ll len, map<ll, vector<ll>>& numbers, map<ll, ll>& dp){
    if(dp[len]) return dp[len];
    if(numbers[len].empty()) return len;
    for(ll test : numbers[len]){
        dp[len] = max(dp[len], testNumber(len + test, numbers, dp));
    }

    return dp[len];
}

void solver(){
    ll n; cin>>n;
    map<ll, vector<ll>> numbers;
    map<ll, ll> dp;
    for(ll i = 1; i <= n; i++){
        ll save; cin>>save;
        if(i == 1) continue;
        numbers[save + i - 1].pb(i-1);
        dp[save + i - 1] = 0;
    }

    ll ans = testNumber(n, numbers, dp);

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