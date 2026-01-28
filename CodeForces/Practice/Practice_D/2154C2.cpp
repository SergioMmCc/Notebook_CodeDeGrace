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

const int limite = 450; // Hasta este numero hay un poco mas de 6e5 primos

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
    int n; cin>>n;
    vector<pli> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].se;
    for(int i = 0; i < n; i++) cin>>a[i].fi;
    sort(all(a));

    ll ans = a[0].fi + a[1].fi;

    set<int> div;
    map<int, ll> div1;
    for(int i = n-1; i > 0; i--){
        int num = a[i].se;

        for(int p : primos){
            if(num % p == 0){
                if(div.find(p) != div.end()){
                    cout<<0<<endl;
                    return;
                }
                div.insert(p);

                while(num % p == 0) num /= p;
            }

            if(num == 1) break;
        }
        if(num > 1){
            if(div.find(num) != div.end()){
                cout<<0<<endl;
                return;
            }
            div.insert(num);
        }

        num = a[i].se + 1;
        for(int p : primos){
            if(num % p == 0){
                if(div1.find(p) != div1.end()) div1[p] = min(a[i].fi, div1[p]);
                else div1[p] = a[i].fi;

                while(num % p == 0) num /= p;
            }
            if(num == 1) break;
        }
        if(num > 1){
            if(div1.find(num) != div1.end()) div1[num] = min(a[i].fi, div1[num]);
            else div1[num] = a[i].fi;
        }
    }

    for(int p : div) ans = min(ans, a[0].fi * (ll)((p - (a[0].se % p)) % p));

    int num = a[0].se;
    for(int p : primos){
        if(num % p == 0){
            if(div.find(p) != div.end()){
                cout<<0<<endl;
                return;
            }
            div.insert(p);

            while(num % p == 0) num /= p;
        }
        if(num == 1) break;
    }
    if(num > 1){
        if(div.find(num) != div.end()){
            cout<<0<<endl;
            return;
        }
        div.insert(num);
    }

    for(int d : div) if(div1.find(d) != div1.end()) ans = min(ans, div1[d]);

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    sieve();
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}