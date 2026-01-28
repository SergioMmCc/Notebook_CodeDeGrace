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

void solver(){
    int n; cin>>n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    sort(a.begin(), a.end());

    vector<int> dp(n); dp[0] = 1;
    vector<int> val; val.pb(a[0].fi);
    for(int i = 1; i < n; i++){
        int ser = a[i].fi - a[i].se;
        auto it = lower_bound(val.begin(), val.end(), ser);
        if(it == val.begin()) dp[i] = 1;
        else{
            --it;
            int index = it - val.begin();
            // cout<<"i -> "<<i<<" index -> "<<index<<endl;
            dp[i] = dp[index] + 1;
        }

        val.pb(a[i].fi);
    }

    int ans = 0;
    // for(int i = 0; i < n; i++) cout<<dp[i]<<' '; cout<<endl;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout<<n - ans<<endl;
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