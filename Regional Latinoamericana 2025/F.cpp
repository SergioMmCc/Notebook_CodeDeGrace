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
typedef pair<ll, int> pli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int limite = 100002;

vector<bool> esPrimo(limite + 1, 1);
vector<int> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++)
        if(esPrimo[i]) primos.pb(i); 
}

void solver(){
    string s; cin>>s;
    int n = sz(s);
    int take = max(0, n - 10);
    ll num = 0;
    for(int i = 0; i < min(n, 10); i++){
        num *= 10;
        num += (int)(s[i] - '0');
    }

    // cout<<num<<endl;

    map<ll, int> dec;

    if(take > 0){
        dec[2] += take;
        dec[5] += take;
    }
    
    for(int p : primos){
        while(num % p == 0){
            dec[p]++;
            num /= p;
        }
    }

    if(num > 1) dec[num]++;

    cout<<sz(dec)<<endl;
    for(pli a : dec){
        cout<<a.fi<<' '<<a.se<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    sieve();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}