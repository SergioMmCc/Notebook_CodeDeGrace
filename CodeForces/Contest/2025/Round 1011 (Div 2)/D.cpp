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
    vector<ll> a(1);
    for(int i = 1; i <= n; i++){
        ll save; cin>>save;
        if(i <= n - k) a.pb(save);
    }

    n -= k; k++;
    int first = n % k;
    if(!first) first += k;

    ll ans = 0;
    multiset<ll> num;
    for(int i = 1; i <= first; i++) num.insert(a[i]);

    auto it = num.end(); --it;
    ans += *it;
    num.erase(it);

    for(int i = first + 1; i <= n; i += k){
        for(int j = i; j < i + k; j++) 
            num.insert(a[j]);

        it = num.end(); --it;
        ans += *it;
        num.erase(it);
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