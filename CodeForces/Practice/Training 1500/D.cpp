#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    ll n; cin>>n;
    ll ans = n * (n + 1) / 2;
    string s; cin>>s;
    queue<ll> q;
    for(ll i = n - 1; i >= 0; i--){
        if(s[i] == '1') q.push(i + 1);
        else if(!q.empty()){
            ll head = q.front();
            ans -= head;
            q.pop();
        }
    }

    int sustract = q.sz / 2;
    while(sustract--){
        ll head = q.front();
        ans -= head;
        q.pop();
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