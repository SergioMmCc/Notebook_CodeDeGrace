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
    int n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(k == 1){
        ll maxi = 0; int index = -1;
        for(int i = 1; i < n-1; i++){
            if(a[i] > maxi){
                maxi = a[i];
                index = i;
            }
        }

        ll ans = maxi + max(a[0], a[n-1]);
        ans = max(ans, a[0] + a[n-1]);

        cout<<ans<<endl;
        return;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i <= k; i++){
        ans += a[i];
    }

    cout<<ans<<endl;
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