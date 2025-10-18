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

const int maxn = 300001, inf = 300000;
vector<int> dp(maxn, inf);

void preCalc(){
    vector<int> a; a.pb(1);
    int k = 1, calc = 1;
    while(calc <= maxn){
        a.pb(calc);
        k++;
        calc = (k * (k + 1) * (k + 2)) / 6;
    }

    dp[0] = 0;
    for(int i = 1; i < maxn; i++){
        for(int j = 0; a[j] <= i; j++){
            dp[i] = min(dp[i], 1 + dp[i - a[j]]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    preCalc();
    while(t--){
        int num; cin>>num;
        cout<<dp[num]<<endl;
    }

    return 0;
}