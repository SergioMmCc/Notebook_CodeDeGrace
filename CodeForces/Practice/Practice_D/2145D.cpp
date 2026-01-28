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

const int maxn = 31;
vector<vector<vector<int>>> dp(31, vector<vector<int>>(436, vector<int>(1)));

int cnt(vector<int>& a){
    int ans = 0;
    int n = sz(a);
    for(int i = 0; i < n; i++){
        int maxi = a[i];
        for(int j = i + 1; j < n; j++){
            if(a[j] < maxi){
                ans += n - j;
                break;
            }
            maxi = a[j];
        }
    }

    return ans;
}

void calc(){
    dp[1][0] = {1};
    dp[2][0] = {1, 2};
    dp[2][1] = {2, 1};
    for(int i = 3; i < maxn; i++){
        int cuad = (i*i - i) / 2;
        int cl = cuad - i + 1;
        for(int j = 0; j <= cl; j++){
            if(sz(dp[i-1][j]) == 1) continue;
            for(int k = 0; k < i; k++){
                vector<int> cop;
                for(int x = 0; x < i - 1; x++){
                    if(x == k) cop.pb(i);
                    cop.pb(dp[i-1][j][x]);
                }
                if(sz(cop) < i) cop.pb(i);

                int tot = cnt(cop);
                if(sz(dp[i][tot]) == 1){
                    dp[i][tot] = cop;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calc();
    int t = 1;
    cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        for(int x : dp[n][k]) cout<<x<<' ';
        cout<<endl;
    }

    return 0;
}