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

void solver(){
    ll n, x; cin>>n>>x;
    if(x == 0){
        if(n == 1) cout<<-1<<endl;
        else if(n % 2 == 0) cout<<n<<endl;
        else cout<<5 + n - 2<<endl;
        return;
    }
    if(x == 1){
        if(n % 2) cout<<n<<endl;
        else cout<<5 + n - 2<<endl;
        return;
    }

    ll ans = x;
    ll m = 0;
    ll aux = x;
    while(aux > 0){
        if(aux % 2) m++;
        aux /= 2;
    }

    if(n <= m){
        cout<<x<<endl;
        return;
    }

    ll p = n - m;
    ans += p + (p % 2);
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