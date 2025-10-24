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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    map<int, int> div, div1;
    for(int i = 0; i < n; i++){
        int num = a[i];
        if(num == 1){
            div1[num + 1] = 1;
            continue;
        }
        for(int p : primos){
            if(!(num % p)){
                if(div.find(p) != div.end()){
                    cout<<0<<endl;
                    return;
                }
                div[p] = 1;
                while(num % p == 0) num /= p;
                if(num == 1) break;
            }
        }

        if(num > 1){
            if(div.find(num) != div.end()){
                cout<<0<<endl;
                return;
            }
            div[num] = 1;
        }

        num = a[i] + 1;
        for(int p : primos){
            if(!(num % p)){
                div1[p] = 1;
                while(num % p == 0) num /= p;
                if(num == 1) break;
            }
        }

        if(num > 1) div1[num] = 1;
    }

    for(const auto& par : div){
        int p = par.first;
        if(div1.find(p) != div1.end()){
            cout<<1<<endl;
            return;
        }
    }

    cout<<2<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    sieve();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}