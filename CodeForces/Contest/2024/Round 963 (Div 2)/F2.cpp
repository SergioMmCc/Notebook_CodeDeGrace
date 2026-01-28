#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

typedef pair<ll, ll> pll;

ll gcd (ll a, ll b) {
    ll temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

ll mod_inverse(ll a, ll b, ll n) {
    ll g = gcd(a, n);
    if(b % g != 0)
        return -1;
    a /= g; b /= g; n /= g;
    if(n == 1)return 0;
    ll i = n, v = 0, d = 1;
    while(a > 0) {
        ll t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= n;
    if(v < 0)
        v += n;
    return (v * b) % n;
}

void solver() {
    int n;
    ll w, h, k, x = 0, y = 0;
    cin>>n>>k>>w>>h;
    k--;
    string s; cin>>s;
    vector<pll> pos;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U')
            y++;
        else if(s[i] == 'D')
            y--;
        else if(s[i] == 'R')
            x++;
        else
            x--;
        x = (x + 2*w) % (2*w);
        y = (y + 2*h) % (2*h);
        pos.push_back({x, y});
    }
    
    ll ww = 2*w / gcd(2*w, x);
    ll hh = 2*h / gcd(2*h, y);
    ll ans = 0, mcm = lcm(hh, ww);
    
    for(pll j : pos){
        ll xj = j.first, yj = j.second;
        if(xj) xj = 2*w - xj;
        if(yj) yj = 2*h - yj;
        
        ll cx = mod_inverse(x, xj, 2*w);
        ll cy = mod_inverse(y, yj, 2*h);
        if(cx == -1 || cy == -1)
            continue;
        
        ll dc = (cy - cx) % hh;
        if(dc < 0) dc += hh;
        
        ll z = mod_inverse(ww, dc, hh);
        if(z == -1)
            continue;
            
        ll solution = cx + z*ww;
        if(solution <= k)
            ans += (k - solution) / mcm + 1;
    }
    
    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}