#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int top=2e5, INF=1e9, MOD=1e9+7;
int vec[top+7];

void solve(){
    ll r, x1, y1, x2, y2;
    cin>>r>>x1>>y1>>x2>>y2;

    ll dx = x1-x2;
    ll dy = y1-y2;
    double d = sqrtl(dx*dx + dy*dy);

    r *= 2;
    double ans = d/r;
    cout<<ceil(ans)<<"\n";
}

signed main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); 
    solve();
    return 0;
}