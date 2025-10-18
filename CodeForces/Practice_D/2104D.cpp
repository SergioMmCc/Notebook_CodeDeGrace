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

const int limite = 6000000;

vector<bool> esPrimo(limite + 1, 1);
vector<ll> sum(1);
void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(ll i = 2; i <= limite; i++){
        if(esPrimo[i]) sum.pb(sum[sum.sz - 1] + i);
    }
}

void solver(){
    int n; cin>>n;
    ll total = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        total += a[i];
    }

    sort(a.begin(), a.end());
    ll take = 0;
    for(int i = 0; i < n; i++){
        if(total - take >= sum[n-i]){
            cout<<i<<endl;
            return;
        }

        take += a[i];
    }

    cout<<n-1<<endl;
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