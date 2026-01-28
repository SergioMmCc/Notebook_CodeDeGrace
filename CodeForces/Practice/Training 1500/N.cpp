#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<ll, int> pli;
const int MAXN = 3e5 + 5;
const int lgn = 18;
const ll inf = 1e18;
ll dp[MAXN][11];
pli rmq[MAXN][lgn + 1];

ll calc(int i, int j, pli rmq[][lgn + 1], int k){
    if(dp[i][j] != inf) return dp[i][j];

    for(int index = 0; index <= k; index++){
        if(i - index - 1 < 0 || j - index < 0) continue;
        ll secondTerm = calc(i - index - 1, j - index, rmq, k);
        int lg = 31 - __builtin_clz(index);
        pli mini = min(rmq[i - index][lg], rmq[i - (1 << lg) + 1][lg]);
        ll sum = mini.first * (index + 1); //[l, r]
        dp[i][j] = min(dp[i][j], secondTerm + sum);
    }

    return dp[i][j];
}

void solver(){
    int n, k; cin>>n>>k;
    vector<ll> a(n+1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(i == 0) dp[i][j] = 0;
            else dp[i][j] = inf;
        }
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        rmq[i][0] = {a[i], i};
    }

    //Llenar sparse table
    for (int j = 1; j <= lgn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
    
    ll ans = calc(n, k, rmq, k);
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