#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

using ld = long double;
using ll = long long;
typedef pair<ld, ll> pdl;
typedef pair<ll, ll> pll;

void solver(){
    ll n, m;cin>>n>>m;
    ll ans = 0;
    vector<pll> a(n); vector<pdl> b(n);
    for(ll i = 0; i < n; i++){
        ld c, p; cin>>c>>p;
        a[i] = {c, p};
        ld save = c/p;
        b[i] = {save, i};
    }
    
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    // for(int i = 0; i < n; i++)
    //     cout<<"first -> "<<b[i].first<<" second -> "<<b[i].second<<endl;
    
    ll cm = 1;
    for(ll i = 0; i < n; i++){
        ans += cm * a[b[i].second].first;
        cm += a[b[i].second].second;
        
        // cout<<"ans -> "<<ans<<" cm -> "<<cm<<endl;
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