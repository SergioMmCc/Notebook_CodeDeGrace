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

const int limite = 100000; // Hasta este numero hay un poco mas de 6e5 primos

vector<bool> esPrimo(limite + 1, 1);
vector<ll> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(ll i = 2; i < limite; i++){
        if(esPrimo[i]) primos.pb(i);
    }
}

void solver(){
    ll p, q; cin>>p>>q;
    if(p % q){
        cout<<p<<endl;
        return;
    }

    ll divi = p;
    for(ll pri : primos){
        if(q == 1) break;
        int count = 0;
        // cout<<"pri -> "<<pri<<endl;
        while(q % pri == 0){
            count++;
            q /= pri;
        }

        if(!count) continue;

        ll aux = p;
        int count2 = 0;
        while(aux % pri == 0){
            count2++;
            aux /= pri;
        }

        ll calc = 1;
        while(count <= count2){
            calc *= pri;
            count++;
        }

        // cout<<"pri -> "<<pri<<" divi -> "<<divi<<endl;
        divi = min(divi, calc);
    }

    if(q > 1){
        ll pri = q;
        int count = 1, count1 = 0;
        ll aux = p;
        while(aux % pri == 0){
            count1++;
            aux /= pri;
        }

        ll calc = 1;
        while(count <= count1){
            calc *= pri; 
            count++;
        }
        divi = min(divi, calc);
    }

    // cout<<"divi -> "<<divi<<endl;
    cout<<p / divi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    sieve();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}