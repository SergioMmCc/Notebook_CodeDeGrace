#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solver(){
    ll n, k; cin>>n>>k;
    ll kk = k*(k-1)/2;
    ll total = (n+k)*(n+k-1)/2 - kk;
    ll totalMid = total/2;
    
    // cout<<"total -> "<<total<<" totalMid -> "<<totalMid<<" kk -> "<<kk<<endl<<endl;
    ll l = 0, r = n-1;
    ll ans = total;
    while(l <= r){
        ll m = (l+r)/2;
        ll test = (m+k)*(m+k-1)/2 - kk;
        ans = min(ans, abs(total - 2*test));
        // cout<<"l -> "<<l<<" r -> "<<r<<" m -> "<<m<<" test -> "<<test<<" ans -> "<<ans<<endl;
        
        if(test == totalMid)break;
        else if(test > totalMid) r = m - 1;
        else l = m + 1;
    }
    
    cout<<ans<<endl;
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}