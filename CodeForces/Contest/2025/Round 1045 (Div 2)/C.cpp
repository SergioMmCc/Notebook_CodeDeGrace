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

void solver(){
    int n; cin>>n;
    vi a(n+2); a[0] = 1e9;
    if(n & 1) a[n+1] = 1e9;
    for(int i = 1; i <= n; i++) cin>>a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i += 2){
        if(a[i] > min(a[i-1], a[i+1])){
            ans += (ll)a[i] - (ll)min(a[i+1], a[i-1]);
            a[i] = min(a[i+1], a[i-1]);
        }
    }
    for(int i = 2; i <= n; i += 2){
        if(a[i] < a[i+1] + a[i-1]){
            if(i+1 < n && a[i+1]){
                ll take = a[i+1] + a[i-1] - a[i];
                ans += take;
                a[i+1] -= take;
            }
            else{
                ll take = a[i+1] + a[i-1] - a[i];
                ans += take;
                a[i-1] -= take;
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
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}