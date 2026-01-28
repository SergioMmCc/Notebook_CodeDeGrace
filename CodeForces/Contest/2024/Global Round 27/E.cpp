#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

ll const inf = 1e18;

void solver() {
    ll x, y, z, k; cin>>x>>y>>z>>k;
    ll d = 0, ans = inf, aux = 0, sum = 0;
    while(z > 0){
        ll dd = d + 1, lastdd = d;
        ll w = (z + dd - 1) / dd;
        ll test = inf;
        while(dd <= d + k){
            test = min(test, y * w + x * (dd - d));
            w--;
            if(w == 0)break;
            lastdd = dd;
            dd = (z + w - 1) / w;
            w = (z + dd - 1) / dd;
            if(dd == lastdd){
                dd++; lastdd++;
                w = (z + dd - 1) / dd;
            }
        }
        aux = sum + test;
        ans = min(ans, aux);
        d += k;
        z -= d;
        sum += k*x + y;
    }

    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}