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

ll mod = 1e9 + 7;

ll mod_inverse(ll a){
    ll i = mod, v = 0, d = 1;
    while(a > 0) {
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
    int q; cin>>q;
    vector<ll> a(q+1);
    ll m = 1, b = 0;
    for(int i = 1; i <= q; i++){
        int op; cin>>op;
        if(op == 1){
            ll val; cin>>val;
            a[i] = (((val * mod_inverse(m)) % mod) - b + mod) % mod;
            // cout<<"i -> "<<i<<" a[i] -> "<<a[i]<<endl;
        }
        else if(op == 2){
            ll val; cin>>val;
            b = (b + val + mod) % mod;
        }
        else if(op == 3){
            ll p, q; cin>>p>>q;
            p = (p + mod) % mod;
            q = (q + mod) % mod;
            q = mod_inverse(q);
            p = (p * q) % mod;
            m = (m * p) % mod;
            b = (b * p) % mod;
        }
        else{
            int idx; cin>>idx;
            cout<<(((a[idx] * m) % mod) + b) % mod<<endl;
        }
    }
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