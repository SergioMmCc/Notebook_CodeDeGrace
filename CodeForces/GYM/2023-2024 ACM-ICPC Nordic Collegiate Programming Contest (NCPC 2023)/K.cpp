#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
#define int long long

vector<ll> pot2(62);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 62; i++) pot2[i] = pot2[i-1] * 2;
}

map<ll, int> used;

int ask(ll x){
    if(used.find(x) != used.end()) return used[x];

    cout<<"buf["<<x<<"]"<<endl;
    int ans; cin>>ans;
    used[x] = ans;
    return ans;
}

void contestar(ll x){
    cout<<"strlen(buf) = "<<x<<endl;
}

void solver(){
    int ans = 1, index = 0;
    while(ans){
        index++;
        ans = ask(pot2[index]);
    }

    ll l = pot2[index - 1], r = pot2[index];
    ll n = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        ans = ask(m);

        if(!ans){
            r = m - 1;
            n = m;
        }
        else l = m + 1;
    }

    contestar(n);
}

signed main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}