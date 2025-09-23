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
typedef pair<int, pii> piii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, k; cin>>n>>k;
    vector<int> level(n+1); level[1] = 1;
    vector<int> a(n+1); a[1] = 1;
    vector<bool> pa(n+1);
    for(int i = 2; i <= n; i++){
        int num; cin>>num;
        pa[num] = 1;
        level[i] = level[num] + 1;
        a[level[i]]++;
    }

    int last = n;
    for(int i = 2; i <= n; i++){
        if(!pa[i]) last = min(last, level[i]);
    }

    vector<vector<piii>> dp(last + 1, vector<piii>(k+1, {-1, {0, 0}}));
    piii zero = {0, {0, 0}};
    for(int i = 0; i <= last; i++){
        dp[i][0] = zero;
    }
    for(int i = 1; i <= last; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = {dp[i-1][j].fi, {i-1, j}};
            if(j - a[i] >= 0 && dp[i-1][j - a[i]].fi != -1) dp[i][j] = max(dp[i][j], {dp[i-1][j - a[i]].fi + 1, {i-1, j - a[i]}});
        }
    }

    piii maxi = zero;
    for(int j = 0; j <= k; j++){
        if(dp[last][j].fi != -1) maxi = dp[last][j];
    }

    set<int> idx;
    while(maxi != zero){
        if(dp[maxi.se.fi][maxi.se.se].fi < maxi.fi)
            idx.insert(maxi.se.fi + 1);
        
        maxi = dp[maxi.se.fi][maxi.se.se];
    }

    int ans = 0, n1 = n - k;
    for(int i = 1; i <= last; i++){
        if(idx.find(i) != idx.end()) ans++;
        else{
            if(a[i] <= n1){
                ans++;
                n1 -= a[i];
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}