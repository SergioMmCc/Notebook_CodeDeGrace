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
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 1e6;

ll calc(ll xr, ll xl, ll yd, ll yu){
    return (xr - xl + 1) * (yd - yu + 1);
}

void solver(){
    int n; ll k; cin>>n>>k;
    vector<pll> p(n);
    ll maxx = -inf, minx = inf, maxy = -inf, miny = inf;
    for(int i = 0; i < n; i++){
        ll x, y; cin>>x>>y;
        p[i] = {x, y};
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
    }

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    ll ans = calc(maxx, minx, maxy, miny);
    for(int i = 0; i < n; i++){
        ll x = p[i].fi, y = p[i].se;

        ans = max(ans, calc(maxx, min(minx, x - k), maxy, min(miny, y - k)));
        ans = max(ans, calc(maxx, min(minx, x - k), max(maxy, y + k), miny));
        ans = max(ans, calc(max(maxx, x + k), minx, maxy, min(miny, y - k)));
        ans = max(ans, calc(max(maxx, x + k), minx, max(maxy, y + k), miny));
    }

    // Mover uno arriba y otro al lado
    ll dy = maxy - miny, dx = maxx - minx;
    if(dx > dy) swap(dx, dy);
    ll add = min(k, dy - dx);
    k -= add;
    dx += add + k / 2;
    dy += (k + 1) / 2;
    ans = max(ans, (dy + 1) * (dx + 1));

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