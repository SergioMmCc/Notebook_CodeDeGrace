#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

typedef pair<ll, ll> pll;

void solver() {
    int n, k;
    ll w, h, x = 0, y = 0;
    cin>>n>>k>>w>>h;
    string s; cin>>s;
    map<pll, int> pos;
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
        pos[{x, y}]++;
    }
    
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ll vx, vy;
        vx = (((-x*i) % (2*w)) + 2*w) % (2*w);
        vy = (((-y*i) % (2*h)) + 2*h) % (2*h);
        ans += (ll)pos[{vx, vy}];
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