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

const int limite = 3e6;

vector<bool> esPrimo(limite + 1, 1);
vector<int> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i <= limite; i++){
        if(esPrimo[i]) primos.pb(i);
    }
}

void solver(){
    int n; cin>>n;
    vector<int> ans(n+1);

    int l = 0, r = n, s = n / 2, i = 0;
    while(primos[i] < s){
        l = primos[i];
        i++;
    }

    r = primos[i];
    if(abs(l - s) < abs(r - s)){
        r = l + 1;
        i = 1;
        while(i <= n){
            if((l > 0 && i % 2) || r > n){
                ans[i] = l;
                l--;
            }
            else{
                ans[i] = r;
                r++;
            }

            i++;
        }
    }
    else{
        l = r - 1;
        i = 1;
        while(i <= n){
            if((r <= n && i % 2) || !l){
                ans[i] = r;
                r++;
            }
            else{
                ans[i] = l;
                l--;
            }

            i++;
        }
    }

    for(i = 1; i <= n; i++) cout<<ans[i]<<' ';
    cout<<endl;
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