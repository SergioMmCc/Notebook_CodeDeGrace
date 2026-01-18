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
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e6 + 3;
vector<ll> fact(mod);
// Llamar antes de usar lucas
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < mod; i++) fact[i] = (fact[i-1] * (ll)i) % mod;
}

ll lucasBinomial(ll n, ll m){
    ll ans = 1;
    while(n > 0 || m > 0){
        ll ni = n % mod;
        ll mi = m % mod;
        if(mi > ni) return 0;
        ans *= (fact[ni] * mod_inverse((fact[mi] * fact[ni - mi]) % mod)) % mod;
        ans %= mod;
        n /= mod;
        m /= mod;
    }
    return ans;
}

void solver(){
    
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