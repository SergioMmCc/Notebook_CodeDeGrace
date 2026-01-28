#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    ll n; cin>>n;
    ll ans = 0;
    for(ll i = 1, multi = 1; i <= n; i++, multi += 2) ans += multi * i;
    cout<<ans<<' '<<2*n<<endl;

    for(int i = n; i > 0; i--){
        cout<<1<<' '<<i;
        for(int j = 1; j <= n; j++) cout<<' '<<j;
        cout<<endl;
        cout<<2<<' '<<i;
        for(int j = 1; j <= n; j++) cout<<' '<<j;
        cout<<endl;
    }
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