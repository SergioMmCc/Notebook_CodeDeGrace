#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver() {
    ll n, a, b, x;
    cin>>n>>a>>b>>x;
    a *= 5; b *= 5; x *= 2;
    ll num = n * (a + b + x);
    ld ans = (ld)num / 10.0;
    cout<<fixed<<setprecision(1)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}