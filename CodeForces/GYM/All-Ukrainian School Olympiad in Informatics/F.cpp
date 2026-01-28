#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pll;

const ll inf = 1e18;

void solver(){
    int n; cin>>n;
    vector<pll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    ll v; cin>>v;

    // Tranformar los puntos
    for(int i = 0; i < n; i++){
        ll p = -a[i].fi + v * a[i].se, q = a[i].fi + v * a[i].se;
        a[i] = {p, q};
    }
    sort(a.begin(), a.end());

    // LIS s1
    vector<ll> d1(n+1, inf); d1[0] = -inf;
    for(int i = 0; i < n; i++){
        if(a[i].fi < 0 || a[i].se < 0) continue;

        auto it = upper_bound(d1.begin(), d1.end(), a[i].se);
        if(it == d1.end()) continue;

        int index = it - d1.begin();
        d1[index] = a[i].se;
    }

    int s1 = 0;
    for(int i = 1; i <= n; i++){
        if(d1[i] != inf) s1 = i;
    }

    // LIS s2
    vector<ll> d2(n+1, inf); d2[0] = -inf;
    for(int i = 0; i < n; i++){
        auto it = upper_bound(d2.begin(), d2.end(), a[i].se);
        if(it == d2.end()) continue;

        int index = it - d2.begin();
        d2[index] = a[i].se;
    }

    int s2 = 0;
    for(int i = 1; i <= n; i++){
        if(d2[i] != inf) s2 = i;
    }

    cout<<s1<<' '<<s2<<endl;
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