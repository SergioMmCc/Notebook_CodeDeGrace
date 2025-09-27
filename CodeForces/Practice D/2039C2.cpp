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
    ll x, m; cin>>x>>m;

    // if(x == 1){
    //     cout<<m<<endl;
    //     return;
    // }

    if(x >= m){
        ll ans = 0;
        for(ll y = 1; y <= m; y++) if((x ^ y) % y == 0) ans++;
        cout<<ans<<endl;
        return;
    }

    // m > x
    ll ans = 0;
    for(ll y = 1; y < x; y++) if((x ^ y) % y == 0) ans++;

    ll div = (m / x) * x;
    if(((div + x) ^ x) <= m && ((div + x) ^ x) > 0) ans++;
    if((div ^ x) <= m) ans++;

    ans += (m - x) / x;
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