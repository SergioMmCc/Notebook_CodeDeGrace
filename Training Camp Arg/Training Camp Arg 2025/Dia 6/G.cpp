#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
const int limite = 100010; // Hasta este numero hay un poco mas de 6e5 primos

vector<bool> esPrimo(limite + 1, 1);
vector<ll> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++){
        primos.pb(i);
    }
}

void solver(){
    ll n; cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return;
    }
    
    ll ans = 1, aux = n;
    for(int i = 0; primos[i] * primos[i] <= aux; i++){
        if(aux % primos[i]) continue;

        ll count = 0;
        while(aux % primos[i] == 0){
            count++;
            aux /= primos[i];
        }

        ans *= (2*count + 1);
    }

    if(aux > 1) ans *= 3;

    ans++;
    ans /= 2;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    sieve();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}