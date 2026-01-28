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
    ll n; cin>>n;
    set<ll> num;
    for(int i = 0; i < n; i++){
        ll save; cin>>save,
        num.insert(save);
    }

    if(n == 1){
        if(*num.begin() == 1) cout<<'*'<<endl;
        else cout<<*num.begin()<<' '<<1<<endl;
        return;
    }
    if(n == 2){
        ll aux = *num.begin(), big = *num.rbegin();
        if(aux != 1) cout<<big<<' '<<1<<endl;
        else{
            ll r = sqrt(big);
            if(r * r == big) cout<<big<<' '<<r<<endl;
            else cout<<big * big<<' '<<big * big<<endl;
        }
        return;
    }

    ll big = *num.rbegin();
    ll ans = 0;
    bool cond = 1;
    for(ll test : num){
        ll com = big / test;
        if(com * test != big) cond = 0;
        else{
            auto it = num.find(com);
            if(it == num.end()){
                if(ans) cond = 0;
                else ans = com;
            }
        }
    }

    ll r = sqrt(big);
    if(r * r == big){
        auto it = num.find(r);
        if(it == num.end()){
            if(ans) cond = 0;
            else ans = r;
        }
    }

    if(ans && cond){
        cout<<big<<' '<<ans<<endl;
        return;
    }

    auto it = num.lower_bound(2);
    ans = *it * big;
    cout<<ans<<' '<<ans<<endl;
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