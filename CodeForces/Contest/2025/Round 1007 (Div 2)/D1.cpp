#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n, l, r; cin>>n>>l>>r;
    vector<int> a(n+1), ps(n+1);
    int lastImpar = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ps[i] = ps[i-1] ^ a[i];
    }

    if(n % 2) lastImpar = ps[n];
    else lastImpar = ps[n] ^ ps[n / 2];

    if(l <= n){
        cout<<a[l]<<endl;
        return;
    }

    l /= 2;

    int ans = 0;
    while(!(l % 2) && l > n){
        ans ^= lastImpar;
        l /= 2;
    }


    if(l <= n) ans ^= ps[l];
    else ans ^= lastImpar;

    cout<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}