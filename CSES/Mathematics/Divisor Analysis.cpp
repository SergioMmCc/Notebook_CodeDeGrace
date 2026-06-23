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

const ll mod = 1e9 + 7;

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

void solver(){
    int n; cin>>n;
    vll save(n);
    ll t = 1, t2 = 1, o = 1, num = 1;
    bool cond = 0;
    for(int i = 0; i < n; i++){
        ll p, a; cin>>p>>a;
        save[i] = {p, a};
        t = (t * (a + 1)) % mod;
        if(!cond && (a & 1)){
            cond = 1;
            t2 = (t2 * ((a+1)/2)) % (mod - 1);
        }
        else t2 = (t2 * (a + 1)) % (mod - 1);
        ll aux = (((myPow(p, a + 1) - 1 + mod) % mod) * mod_inverse(p - 1)) % mod;
        o = (o * aux) % mod;
        num = (num * myPow(p, a)) % mod;
    }

    if(!cond){
        num = 1;
        for(pll x : save) num = (num * myPow(x.fi, x.se / 2)) % mod;
    }

    ll u = myPow(num, t2);

    cout<<t<<' '<<o<<' '<<u<<endl;
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