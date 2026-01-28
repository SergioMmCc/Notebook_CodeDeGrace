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
#define int long long

void solver(){
    int n, k; ll x; cin>>n>>k>>x;
    vector<ll> a(n+1), ps(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ps[i] = ps[i-1] + a[i];
    }

    int ans = 0;
    int index = 0;
    for(int i = k; !index && i >= 0; i--){
        if(ps[n] * (k - i) >= x){
            index = i;
        }
    }

    ans += n * index;

    int count = ps[n] * (k - index - 1);
    for(int i = n; i > 0; i--){
        if(count + ps[n] - ps[i-1] >= x){
            ans += i;
            break;
        }
    }

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