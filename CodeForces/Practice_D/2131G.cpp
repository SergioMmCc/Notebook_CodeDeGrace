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

const ll mod = 1e9 + 7;
const int maxn = 30, inf = 1e9 + 1;

ll myPow(ll b, ll e){
    ll result = 1;
    while(e > 0){
        if(e % 2 == 1)
            result = ((b % mod) * (result % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e /= 2;
    }
    return result;
}

ll mod_inverse(ll a){
    ll i = mod, v = 0, d = 1;
    while(a > 0){
        ll t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= mod;
    if(v < 0)
        v += mod;
    return v; // (a * v) % mod = 1
}

ll calc30(ll x){ // Al parecer funciona
    ll last = 1, take = 0;
    ll ans = 1;
    for(int i = maxn - 1; i >= 0; i--){
        ll pot = last - take;
        take *= 2LL;
        last *= 2LL;
        if(!(x & (1LL << i))){
            pot--;
            take++;
        }

        ans *= myPow((ll)i + 1, pot);
        ans %= mod;
    }

    return ans;
}

void solver(){
    int n; ll k; cin>>n>>k;
    int m = inf;
    ll x = 0;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        if(num > maxn) m = min(m, num);
        else x |= (1LL << (num - 1));
    }

    ll ans = calc30(x);
    if(!m || x >= k){
        x -= k;
        ll res = calc30(x);
        ans = (ans * mod_inverse(res)) % mod;
        cout<<ans<<endl;
        return;
    }

    ans *= (ll)m; ans %= mod;
    if(x + 1 == k){
        cout<<ans<<endl;
        return;
    }

    k -= x + 1;
    for(int i = 0; i < 31; i++) x |= (1LL << i);
    ans *= calc30(x); ans %= mod;
    x -= k;
    ll res = calc30(x);
    ans = (ans * mod_inverse(res)) % mod;
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