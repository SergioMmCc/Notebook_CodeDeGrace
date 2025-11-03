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

void solver(){
    string s; cin >> s;
    int n = s.sz;
    vector<ld> dp(n+1);
    for(int i = 0; i <= n; ++i){
        dp[i] = 0.0;
    }
    for(int i = n-1; i >= 0; --i){
        //cout << dp[i] << endl;
        for(int j = i; j < n; ++j){
            ll prob = 1;
            ld num = 0;
            for(int k = i; k <= min(j, i + 11); ++k){
                num *= ld(10);
                num += ld(s[k] - '0');
                if(k > i)
                    prob *= 10;
            }
            //cout << num << " " << prob << endl;
            ll nu = 9;
            ll dem = 20;
            if(j == n-1){
                nu = 1;
                dem = 2;
            }
            dp[i] += (((num + dp[j+1]) * nu) / (dem * prob)) + (((num - dp[j+1]) * nu) / (dem * prob));
        }
        //cout << dp[i] << endl;
    }
    cout << fixed << setprecision(7) << dp[0]<< endl;
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