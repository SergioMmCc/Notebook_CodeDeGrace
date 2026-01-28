#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solver(){
    ll n, q;cin>>n>>q;
    vector<ll> a(n+1);
    vector<ll> total(2*n+1); total[0] = 0;
    for(ll i = 1; i <= n; i++){
        cin>>a[i];
        total[i] = a[i] + total[i-1];
    }
    for(ll i = 1; i <= n; i++)
        total[i+n] = total[n] + total[i];
        
    
    while(q--){
        ll ans = 0;
        ll l, r; cin>>l>>r;
        ll lc = (l + n - 1)/n, rc = (r + n - 1)/n;
        ll lp = (l % n), rp = (r % n);
        if(lp == 0)lp = n;
        if(rp == 0)rp = n;
        
        // cout<<"lc -> "<<lc<<" lp -> "<<lp<<" rc-> "<<rc<<" rp -> "<<rp<<endl;
        if(rc != lc){
            ll add = rc - lc - 1;
            ans = add*total[n];
            // cout<<ans<<endl;
            //Para l
            ans += total[n] + total[lc-1] - total[lc + lp - 2];
            // cout<<ans<<endl;
            
            //Para r
            ans += total[rc + rp - 1] - total[rc-1];
            // cout<<ans<<endl;
        }
        else{
            ll c = lc;
            ans = total[rp + c - 1] - total[lp + c - 2];
        }
        
        
        cout<<ans<<endl;
    }
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}