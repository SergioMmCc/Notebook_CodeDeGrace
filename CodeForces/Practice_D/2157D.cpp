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

void solver(){
    int n; ll l, r; cin>>n>>l>>r;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(all(a));

    vector<ll> psl(n+1), psr(n+1);
    for(int i = 1; i <= n; i++){
        psl[i] = psl[i-1] + a[i] - l;
        psr[i] = psr[i-1] + r - a[i];
    }

    ll ans = 0;
    for(int k = 1; k <= n; k++){
        int i = k, j = k+1;
        ans = max(ans, min(-psl[i] + psl[n] - psl[j-1], -psr[n] + psr[j-1] + psr[i]));
        i--; j--;
        ans = max(ans, min(-psl[i] + psl[n] - psl[j-1], -psr[n] + psr[j-1] + psr[i]));
        j++;
        ans = max(ans, min(-psl[i] + psl[n] - psl[j-1], -psr[n] + psr[j-1] + psr[i]));
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