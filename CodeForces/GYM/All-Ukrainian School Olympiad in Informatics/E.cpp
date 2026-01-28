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
    ll n; cin>>n;
    vector<ll> x(n+1), y(n+1), px(n+1), py(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
        px[i] = px[i-1] + x[i];
        py[i] = py[i-1] + y[i];

        ans += (n - 1) * (x[i] * x[i] + y[i] * y[i]);
    }

    for(int i = 1; i <= n; i++){
        ans -= 2 * x[i] * (px[n] - px[i]);
        ans -= 2 * y[i] * (py[n] - py[i]);
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