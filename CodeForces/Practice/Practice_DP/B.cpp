#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> dp(n, -1); dp[0] = 0;

    for(int i = 1; i < n; i++){
        if(s[i] == 'w') continue;

        if(s[i-1] != 'w') dp[i] = dp[i-1];
        if(i - 3 >= 0 && s[i-3] != 'w') dp[i] = max(dp[i], dp[i-3]);
        if(i - 5 >= 0 && s[i-5] != 'w') dp[i] = max(dp[i], dp[i-5]);

        if(dp[i] != -1 && s[i] == '"') dp[i]++;
    }

    cout<<dp[n-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("lepus.in", "r", stdin);
	freopen("lepus.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}