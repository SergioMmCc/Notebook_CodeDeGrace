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

const ld ep = 0.000001;

ld stringToNumber(string s){
    ld ans = 0.0, div = 1.0;
    bool point = 0;
    for(int i = 0; i < s.sz; i++){
        if(s[i] == '.'){
            point = 1;
            continue;
        }

        if(!point && i) ans *= 10.0;
        else if(point){
            div /= 10.0;
            ans += ((ld)(s[i] - '0')) * div;
        }
        else ans += (ld)(s[i] - '0');
    }

    return ans;
}

void solver(){
    string sr, sl, sh; cin>>sr>>sl>>sh;
    ld r = stringToNumber(sr), l = stringToNumber(sl), h = stringToNumber(sh);
    // cout<<r<<' '<<l<<' '<<h<<endl;
    if(r == l){
        cout<<fixed<<setprecision(6)<<h / 2.0<<endl;
        return;
    }

    ld v = M_PI * h * (l * l + r * r + l * r) / 6.0;
    ld den = h / (l - r);

    ld lo = 0.0, hi = h;
    bool cond = 1;
    ld ans;
    while(cond){
        ld hp = (hi + lo) / 2.0;
        ld lp = hp / den + r;

        ld vp = M_PI * hp * (lp * lp + r * r + lp * r) / 3.0;

        if(abs(v - vp) <= ep){
            ans = hp;
            cond = 0;
        }
        else if(v > vp) lo = hp;
        else hi = hp;
    }

    cout<<fixed<<setprecision(6)<<ans<<endl;
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