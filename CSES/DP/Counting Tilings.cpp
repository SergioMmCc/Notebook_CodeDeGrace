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
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;

void solver(){
    int n, m; cin>>n>>m;
    int ans = 0;
    vector<vi> dp(m+1, vi(1 << n));
    dp[0][(1 << n) - 1] = 1;
    for(int i = 0; i <= m; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            stack<pii> q; q.push({0, 0});
            while(!q.empty()){
                int nextMask = q.top().fi, bit = q.top().se; q.pop();
                if(bit == n){
                    if(i == m){
                        if(!nextMask) ans = (ans + dp[i][mask]) % mod;
                        continue;
                    }
                    dp[i+1][nextMask] = (dp[i+1][nextMask] + dp[i][mask]) % mod;
                    continue;
                }
                if(mask & (1 << bit)) q.push({nextMask, bit+1});
                if(!(mask & (1 << bit))) q.push({nextMask | (1 << bit), bit+1});
                if(bit < n-1 && !(mask & (1 << bit)) && !(mask & (1 << (bit+1)))) q.push({nextMask, bit+2});
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
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}