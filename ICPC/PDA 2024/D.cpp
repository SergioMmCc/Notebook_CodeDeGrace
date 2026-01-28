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

const int limite = 1000000; // Hasta este numero hay un poco mas de 6e5 primos

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
    ll n; cin>>n;
    ll r = sqrt(n);
    if(r * r == n){
        cout<<'N'<<endl;
        return;
    }

    int maxx = 0, total = 1;
    for(int p : primos){
        if(n == 1) break;
        int aux = 0;
        while((n % p) == 0){
            aux++;
            n /= p;
        }

        maxx = max(maxx, aux);
        total *= aux + 1;
    }
    if(n > 1){
        maxx = max(maxx, 1);
        total *= 2;
    }
    
    if(total == 4 || total == maxx + 1) cout<<'Y'<<endl;
    else cout<<'N'<<endl;
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