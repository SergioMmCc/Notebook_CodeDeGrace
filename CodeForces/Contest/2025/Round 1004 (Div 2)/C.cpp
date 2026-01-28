#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    ll n; cin>>n;
    ll ans = 11;

    ll start = 0;
    for(ll cifra = 0; cifra <= 10; cifra++){
        start *= 10; start += 9;
        for(ll multiplo = 0; multiplo <= 9; multiplo++){
            ll test = start * multiplo;
            ll aux = n + test;
            bool cond = 0;
            while(!cond && aux > 0){
                if(aux % 10 == 7) cond = 1;
                aux /= 10;
            }
            if(cond) ans = min(ans, multiplo);
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}