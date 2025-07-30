#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, int> pli;

void solver(){
    int n, p, k; cin>>n>>p>>k;
    vector<pli> a(n);
    for(int i = 1; i <= n; i++){
        cin>>a[i-1].fi;
        a[i-1].se = i;
    }
    sort(a.begin(), a.end()); 
    a.pb({0, 0});
    reverse(a.begin(), a.end());
    vector<int> ord(n+1);
    for(int i = 1; i <= n; i++) ord[a[i].se] = i;

    vector<vector<ll>> s(n+1, vector<ll>(p));
    ll sum = 0;
    for(int index = 1; index <= n; index++){
        if(index <= k) sum += a[index].fi;
        int i = ord[index];
        for(int j = 0; j < p; j++) cin>>s[i][j];
    }

    // for(int i = 1; i <= n; i++){
    //     cout<<a[i].fi;
    //     for(int j = 0; j < p; j++) cout<<' '<<s[i][j];
    //     cout<<endl;
    // }

    int lim = 1 << p;
    vector<vector<ll>> dp(n + 1, vector<ll>(lim)); dp[0][0] = sum;
    for(int mask = 0; mask < lim; mask++){
        int count = 0;
        for(int i = 0; i < p; i++){
            if(mask & (1 << i)) count++;
        }

        for(int i = 1; i <= n; i++){
            if(count > i) continue;
            dp[i][mask] = dp[i-1][mask];

            ll res = 0;
            if(k + count > i) res = a[i].fi - a[k + count].fi;

            for(int j = 0; j < p; j++){
                if((mask & (1 << j)) == 0) continue;
                dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1 << j)] - res + s[i][j]);
            }
        }
    }

    cout<<dp[n][lim - 1]<<endl;
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