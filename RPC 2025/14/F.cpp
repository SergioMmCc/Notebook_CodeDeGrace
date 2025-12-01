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

const int limite = 10000; // Hasta este numero hay un poco mas de 6e5 primos

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
    int n, x; cin>>n>>x;

    int cnt = 0;
    int maxi = 0;
    for(int p : primos){
        while(n % p == 0){
            maxi = max(maxi, p);
            n /= p;
            cnt++;
        }
    }

    if(n > 1){
        cnt++;
        maxi = max(maxi, n);
    }

    if(maxi > x) cout<<"what is Obo?"<<endl;
    else cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    sieve();
    while(t--){
        solver();
    }

    return 0;
}