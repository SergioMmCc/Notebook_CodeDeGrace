#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pll;

const ll b1 = 31, b2 = 37, mod1 = 1000000009, mod2 = 998244353;
vector<ll> potB1(28), potB2(28);
void calcPotB(){
    potB1[0] = 1;
    potB2[0] = 1;
    for(int i = 1; i < 28; i++){
        potB1[i] = (potB1[i-1] * b1) % mod1;
        potB2[i] = (potB2[i-1] * b2) % mod2;
    }
}

void calc(string a, vector<map<pll, ll>>& fa){
    for(int i = 0; i < a.sz; i++){
        ll ans1 = 0, ans2 = 0;
        for(int j = i; j < a.sz; j++){
            int idx = a[j] - 'a';
            ans1 = (ans1 + potB1[idx]) % mod1;
            ans2 = (ans2 + potB2[idx]) % mod2;
            fa[j-i][{ans1, ans2}]++;
        }
    }
}

void solver(){
    string a, b; cin>>a>>b;
    vector<map<pll, ll>> fa(a.sz), fb(b.sz);
    // cout<<"en a -> "<<endl;
    calc(a, fa);
    // cout<<endl<<"en b -> "<<endl;
    calc(b, fb);

    ll ans = 0;
    for(int i = 0; i < a.sz; i++){
        for(auto it : fa[i]){
            pll h = it.fi; ll f = it.se;
            auto it2 = fb[i].find(h);
            if(it2 != fb[i].end()) ans += (ll)f * (ll)fb[i][h];
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPotB();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}