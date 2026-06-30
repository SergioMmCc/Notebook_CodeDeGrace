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
    ll n, k; cin>>n>>k;
    vl a(k);
    for(int i = 0; i < k; i++) cin>>a[i];

    ll ans = 0;
    for(int mask = 1; mask < (1 << k); mask++){
        ll num = 1;
        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(mask & (1 << i)){
                cnt++;
                if(a[i] > n / num){
                    num = n+1;
                    break;   
                }
                num *= a[i];
            }
        }
        ans += (cnt & 1) ? (n / num) : -(n / num);
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