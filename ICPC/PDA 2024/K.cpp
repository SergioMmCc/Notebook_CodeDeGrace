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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool isVowel(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

void solver(){
    int n; cin>>n;
    int inf = 3*n + 1;
    vs a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vector<vi> dp(n+1, vi(3, inf));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        if(isVowel(a[i][0])){
            dp[i][0] = min(min(dp[i][0], 1 + dp[i-1][0]), 1 + min(dp[i-1][1], dp[i-1][2]));
            continue;
        }
        dp[i][1] = min(dp[i][1], 1 + dp[i-1][0]);
        dp[i][2] = min(dp[i][2], 1 + dp[i-1][1]);

        if(sz(a[i]) == 1) continue;

        if(isVowel(a[i][1])){
            dp[i][0] = min(dp[i][0], 1 + min(dp[i][1], dp[i][2]));
            continue;
        }

        if(sz(a[i]) > 2 && isVowel(a[i][2])) dp[i][0] = min(dp[i][0], 3 + dp[i-1][0]);
    }

    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    if(ans == inf) cout<<'*'<<endl;
    else cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}