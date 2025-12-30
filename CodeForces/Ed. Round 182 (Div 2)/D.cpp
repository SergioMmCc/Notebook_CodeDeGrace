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

const ll mod = 998244353;

vector<ll> fact(51);
void calcFact(){
    fact[0] = 1;
    for(int i = 1; i < 51; i++) fact[i] = (fact[i-1] * (ll)i) % mod;
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
    vector<int> a(n+1);
    int total = 0;
    for(int i = 0; i <= n; i++){
        cin>>a[i];
        total += a[i];
    }

    int rondas = total / n;
    int left = total % n;
    if(!left){
        for(int i = 1; i <= n; i++){
            if(a[i] > rondas){
                cout<<0<<endl;
                return;
            }
        }

        cout<<fact[n]<<endl;
        return;
    }

    int cnt1 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > rondas + 1){
            cout<<0<<endl;
            return;
        }
        if(a[i] == rondas + 1) cnt1++;
    }

    ll ans = (fact[left] * fact[n - cnt1]) % mod;
    ll den = mod_inverse(fact[left - cnt1]);
    cout<<(ans * den) % mod<<endl;
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