#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const ll mod = 998244353;

void solver(){
    int n; cin>>n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll pot2 = 1;
    ll ans = 0;
    for(int bit = 0; bit <= 31; bit++){
        if(bit) pot2 *= 2;

        ll aux = 0;
        ll c0 = 0, ec0 = 0, c1 = 0, ec1 = 0;
        bool par = 1;
        for(int i = 1; i <= n; i++){
            c0 += ec0; c1 += ec1;
            if(a[i] % 2) par = !par;

            if(a[i] % 2){
                if(!par){
                    ec1++;
                    c1++;
                    aux += c1;
                }
                else{
                    ec0++;
                    c0++;
                    aux += c0;
                }
            }

            else{
                if(!par){
                    aux += c1;
                    ec0++;
                    c0++;
                }
                else{
                    aux += c0;
                    ec1++,
                    c1++;
                }
            }

            a[i] >>= 1;
        }

        aux = ((aux % mod) * (pot2 % mod)) % mod;
        ans = (ans + aux) % mod; 
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}