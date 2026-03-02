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

const int mod = 998244353;

const int maxn = 3001;
vector<vi> trans(maxn);
void preCalc(){
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j <= i && j+i < maxn; j++){
            if(i % j == 0) trans[i].pb(i+j);
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    if(!a[0]) a[0] = 1;
    if(!a[1]) a[1] = 2;

    if(a[0] != 1 || a[1] != 2){
        cout<<0<<endl;
        return;
    }

    vector<vi> dp(n, vi(m+1));
    dp[1][2] = 1;
    for(int i = 1; i < n-1; i++){
        if(a[i]){
            for(int x : trans[a[i]]){
                if(x > m) break;
                if(!a[i+1] || a[i+1] == x) dp[i+1][x] = (dp[i+1][x] + dp[i][a[i]]) % mod;
            }
        }
        else{
            for(int j = i+1; j <= m; j++){
                for(int x : trans[j]){
                    if(x > m) break;
                    if(!a[i+1] || a[i+1] == x) dp[i+1][x] = (dp[i+1][x] + dp[i][j]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for(int j = 1; j <= m; j++) ans = (ans + dp[n-1][j]) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    preCalc();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}