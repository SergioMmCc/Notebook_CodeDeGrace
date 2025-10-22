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

const ll b = 1009, mod = 1000000009;
vector<ll> potB(28);
void calcPotB(){
    potB[0] = 1;
    for(int i = 1; i < 28; i++) potB[i] = (potB[i-1] * b) % mod;
}

void calc(string a, vector<map<ll, ll>>& fa){
    for(int i = 0; i < a.sz; i++){
        ll ans = 0;
        for(int j = i; j < a.sz; j++){
            int idx = a[j] - 'a';
            ans = (ans + potB[idx]) % mod;
            fa[j-i][ans]++;
        }
    }
}

void solver(){
    string a, b; cin>>a>>b;
    vector<map<ll, ll>> fa(a.sz), fb(b.sz);
    // cout<<"en a -> "<<endl;
    calc(a, fa);
    // cout<<endl<<"en b -> "<<endl;
    calc(b, fb);

    ll ans = 0;
    for(int i = 0; i < a.sz; i++){
        for(auto it : fa[i]){
            ll h = it.fi; ll f = it.se;
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