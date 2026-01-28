#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

void solver(){
    int n, w; cin>>n>>w;
    vector<piii> waves;
    while(n--){
        char op; cin>>op;
        if(op == '!'){
            int p, l, a; cin>>p>>l>>a;
            waves.pb({p, {p + l - 1, a}});
        }
        else{
            int ans = 0;
            int p; cin>>p;
            for(piii wave : waves){
                if(wave.first <= p && wave.second.first >= p){
                    if((p - wave.first) % 4 == 0) ans += wave.second.second;
                    else if((p - wave.first) % 4 == 2) ans -= wave.second.second;
                }
            }

            cout<<ans<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}