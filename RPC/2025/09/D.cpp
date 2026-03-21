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

ld ep = 0.0000000001;

ld strToLD(string s){
    ld aux = 1.0, ans = 0.0;
    int len = s.sz;
    bool neg = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        if(s[i] == '-'){
            neg = 1;
            continue;
        }
        int num = s[i] - '0';
        ans += (ld)num * aux;
        aux *= 0.1;
    }

    if(neg) ans *= -1.0;
    return ans;
}

bool test(ld a, ld k){
    k += ep;
    return a <= k && -a <= k;
}

void solver(){
    ld p, r, y; cin>>p>>r>>y;

    ld a = 0.0, b = 4.0;
    ld na, ea, sa, wa;
    for(int idx = 0; idx < 100; idx++){
        ld k = (a + b) / 2.0;
        bool cond = 0;

        ld e, w, n, s;

        // Fijar e o w
        for(int i = 0; !cond && i < 2; i++){
            for(int j = 0; !cond && j < 2; j++){
                if(i){
                    e = (j ? k : -k);
                    w = e - p;
                }
                else{
                    w = (j ? k : -k);
                    e = p + w;
                }

                n = (y - 2 * e  + p + r) / 2.0;
                s = n - r;

                if(test(e, k) && test(w, k) && test(n, k) && test(s, k)){
                    cond = 1;
                    na = n;
                    ea = e;
                    sa = s;
                    wa = w;
                }
            }
        }

        // Fijar n o s
        for(int i = 0; !cond && i < 2; i++){
            for(int j = 0; !cond && j < 2; j++){
                if(i){
                    n = (j ? k : -k);
                    s = n - r;
                }
                else{
                    s = (j ? k : -k);
                    n = r + s;
                }

                e = (y - 2 * n  + p + r) / 2.0;
                w = e - p;

                if(test(e, k) && test(w, k) && test(n, k) && test(s, k)){
                    cond = 1;
                    na = n;
                    ea = e;
                    sa = s;
                    wa = w;
                }
            }
        }

        if(cond) b = k;
        else a = k;
    }

    cout<<fixed<<setprecision(8)<<na<<' '<<ea<<' '<<sa<<' '<<wa<<endl;
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