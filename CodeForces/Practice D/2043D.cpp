#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void ans(ll x, ll y){
    cout<<x<<' '<<y<<endl;
}

void solver(){
    ll l, r, g; cin>>l>>r>>g;
    ll x = l - (l % g), y = r - (r % g);
    if(x < l) x += g;

    if(x > r || y < l){
        ans(-1, -1);
        return;
    }

    for(ll gap = y - x; gap >= 0; gap -= g){
        for(ll a = x, b = x + gap; b <= y; a += g, b += g){
            if(__gcd(a, b) == g){
                ans(a, b);
                return;
            }
        }
    }

    ans(-1, -1);
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