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

const ll larg  = 1000000010;

void precalc_hashing(string s, vector<ll>& h, vector<ll>& ph){
    ll p = 31;
    ll m = 1e9 + 9;

    h[0] = s[0] - 'a' + 1;
    ph[0] = 1;

    for(int i = 1; i < s.sz; i++){
        h[i] = (((h[i-1] * p) % m) + (s[i] - 'a' + 1)) % m;
        ph[i] = (ph[i-1] * p) % m;
    }

}

ll queries(ll l, ll r, vector<ll>& h, vector<ll>& ph){
    ll m = 1000000009;
    if(!l) return h[r];
    return (h[r] - ((h[l-1] * ph[r-l+1]) % m) + m) % m;
}

void solver(){
    string s, t; cin>>s>>t;
    int ls = s.sz, lt = t.sz;

    vector<ll> h(lt), ph(lt);
    precalc_hashing(t, h, ph);

    int c0 = 0, c1 = 0;
    for(int i = 0; i < ls; i++){
        if(s[i] == '0') c0++;
        else c1++;
    }

    int ans = 0;
    for(int y = 1; y < lt; y++){
        if(((ll)lt - (ll)c1 * (ll)y) % (ll)c0) continue;
        ll x = ((ll)lt - (ll)c1 * (ll)y) / (ll)c0;
        if(x <= 0) continue;

        int l = 0;
        ll r0 = larg, r1 = larg;
        if(s[0] == '0'){
            l += x;
            r0 = queries(0, l-1, h, ph);
        }
        else{
            l += y;
            r1 = queries(0, l-1, h, ph);
        }

        bool cond = 1;
        for(int i = 1; cond && i < ls; i++){
            if(s[i] == '0' && r0 == larg){
                r0 = queries(l, l + x - 1, h, ph);
                if(r0 == r1) cond = 0;
                l += x;
                continue;
            }
            if(s[i] == '1' && r1 == larg){
                r1 = queries(l, l + y - 1, h, ph);
                if(r1 == r0) cond = 0;
                l += y;
                continue;
            }

            if(s[i] == '0'){
                if(r0 != queries(l, l + x - 1, h, ph)) cond = 0;
                else l += x;
            }
            else{
                if(r1 != queries(l, l + y - 1, h, ph)) cond = 0;
                else l += y;
            }
        }

        if(cond) ans++;
    }

    cout<<ans<<endl;
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