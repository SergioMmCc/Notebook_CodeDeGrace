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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 33;

void solver(){
    vector<string> dict(6);
    for(int i = 0; i < 6; i++) cin>>dict[i];

    vector<vector<int>> dp(16, vector<int>(26, inf));


    dp[0][dict[5][0] - 'A'] = 2;
    for(int i = 1; i <= 4; i++) dp[0][dict[i][0] - 'A'] = 1;
    dp[0][dict[0][0] - 'A'] = 0;

    // for(int j = 0; j < 26; j++){
    //     cout<<dp[0][j]<<endl;;
    // }

    int ans = inf;
    for(int i = 1; i < 16; i++){
        for(int let = 0; let < 6; let++){
            int j = dict[let][i] - 'A';

            int sum = 0;
            if(let == 5) sum = 2;
            else if(let) sum = 1;

            for(int k = 0; k <= j; k++){
                if(dp[i-1][k] == inf) continue;
                if(j == 'Q' - 'A'){
                    dp[i]['U' - 'A'] = min(dp[i]['U' - 'A'], dp[i-1][k] + sum);
                    if(i == 15) ans = min(ans, dp[i]['U' - 'A']);
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + sum);
                    if(i == 15) ans = min(ans, dp[i][j]);
                }
            }

            // cout<<"i -> "<<i<<" let -> "<<let<<" j -> "<<j<<" dp -> "<<dp[i][j]<<endl;
        }
    }

    // cout<<endl;
    // for(int j = 0; j < 26; j++){
    //     cout<<dp[15][j]<<endl;;
    // }

    if(ans == inf) cout<<"impossible"<<endl;
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