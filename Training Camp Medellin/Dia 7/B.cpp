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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    vector<vi> freq(26, vi(n+1));
    for(int i = 1; i <= n; i++) freq[s[i-1] - 'a'][i]++;
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++){
            freq[i][j] += freq[i][j-1];
        }
    }

    vector<vi> dp(26, vi(n+1));
    for(int c = 0; c < 26; c++){
        for(int l = 1; l <= n; l++){
            for(int r = l; r <= n; r++){
                int need = r - l + 1 - freq[c][r] + freq[c][l-1];
                dp[c][need] = max(dp[c][need], r-l+1);
            }
        }
    }

    for(int c = 0; c < 26; c++){
        for(int i = 1; i <= n; i++){
            dp[c][i] = max(dp[c][i], dp[c][i-1]);
        }
    }

    int q; cin>>q;
    while(q--){
        int k; char c; cin>>k>>c;
        cout<<dp[c - 'a'][k]<<endl;
    }
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