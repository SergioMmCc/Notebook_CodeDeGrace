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
    int n; cin>>n;
    vector<ll> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        total += a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ld ans = 0.0;
    ll aux = 0;
    for(int i = 0; i < n; i++){
        aux += a[i];
        ans = max(ans, (ld)(ld)aux/(ld)total - ((ld)i+1)/(ld)n);
    }

    ans *= 100.0;
    cout<<fixed<<setprecision(10)<<ans<<endl;
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