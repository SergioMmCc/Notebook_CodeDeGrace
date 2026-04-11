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
    int n, k; cin>>n>>k;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    int m; cin>>m;

    if(a[m]){
        for(int i = 1; i <= n; i++) a[i] ^= 1;
    }

    int change = 0;
    for(int i = 1; i <= m; i++){
        a[i] += change;
        a[i] %= 2;
        if(a[i]) change++;
    }

    change = 0;
    for(int i = n; i >=m ; i--){
        a[i] += change;
        a[i] %= 2;
        if(a[i]) change++;
    }

    int l = 0, r = 0;
    for(int i = 1; i < m; i++) l += a[i];
    for(int i = n; i > m; i--) r += a[i];

    int ans = max(l, r);
    if(ans & 1) ans++;
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