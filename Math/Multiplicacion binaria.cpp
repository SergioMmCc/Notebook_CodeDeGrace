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

const ll mod = (ll)1e18 + 3;

ll myPor(ll b, ll e){
    ll result = 0;
    while(e){
        if(e & 1)
            result = ((b % mod) + (result % mod)) % mod;
        b = ((b % mod) + (b % mod)) % mod;
        e >>= 1;
    }
    return result;
}

void solver(){
    ll n; cin>>n;
    cout<<myPor(n, n)<<endl;
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