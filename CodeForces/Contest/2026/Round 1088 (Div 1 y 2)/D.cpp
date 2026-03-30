#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define int long long
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

const int maxn = 1e5 + 1;
const int mod = 1000000007;
vi fact(maxn);
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * i) % mod;
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
    vi b(n+1);
    for(int i = 1; i <= n; i++){
        cin>>b[i];
    }

    vi carr;
    vi ans(n+1);

    for(int i = n; i >= 1; i--){
        int take = 0;
        for(int car : carr){
            int aux = (fact[car] * mod_inverse((fact[i] * fact[car-i]) % mod)) % mod;
            aux = (aux * b[car]) % mod;
            take = (take + aux) % mod;
        }

        b[i] = (b[i] - take + mod) % mod;
        if(b[i]){
            carr.pb(i);
            for(int j = 1; j <= i; j++) ans[j] = (ans[j] + b[i]) % mod;
        }
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<' '; cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    calcFact();
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}