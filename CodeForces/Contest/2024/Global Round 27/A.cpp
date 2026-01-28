#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solver() {
    ll n, m, r, c; cin>>n>>m>>r>>c;
    ll ans = (n - r) * m + (m - 1) * (n - r) + m - c;
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