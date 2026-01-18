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
const int maxn = 1e6 + 4;
vector<ll> fact(maxn);
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = (fact[i-1] * (ll)i) % mod;
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
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
 
    int mult = 30;
    for(int i = 0; i < n; i++){
        int cnt = 0, pot = 2;
        while(a[i] * pot <= b[i]){
            cnt++;
            pot *= 2;
        }
 
        mult = min(mult, cnt);
    }
 
    ll ans1 = mult;
    ll num = 1, den = 1;
 
    vector<vi> calc(n, vi(mult + 1));
    for(int i = 0; i < n; i++){
        int aux = b[i];
        for(int j = mult; j > 0; j--){
            if(aux & 1){
                calc[i][j] = 1;
                ans1++;
            }
            aux >>= 1;
        }
        int take = aux - a[i];
        ans1 += take;
        den = (den * fact[take]) % mod;
        calc[i][0] = take;
    }
 
    for(int j = 0; j <= mult; j++){
        int add = 0;
        for(int i = 0; add < maxn && i < n; i++) add += calc[i][j];
        if(add >= maxn){
            num = 0;
            break;
        }
        num = (num * fact[add]) % mod;
    }
 
    cout<<ans1<<' '<<(num * mod_inverse(den) % mod)<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcFact();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }
 
    return 0;
}