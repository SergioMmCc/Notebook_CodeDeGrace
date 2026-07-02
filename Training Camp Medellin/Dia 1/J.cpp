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

const ll mod = 998244353;
vl fact(2001);
void calcFact(){
    fact[0] = 1;
    for(ll i = 1; i < 2001; i++) fact[i] = (fact[i-1] * i) % mod;
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

void solver(){
    ll n, m, k; cin>>n>>m>>k;
    ll ans = (fact[n-1] * mod_inverse((fact[n-1-k] * fact[k]) % mod)) % mod;
    ans = (ans * ((myPow(m-1, k) * m) % mod)) % mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcFact();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}