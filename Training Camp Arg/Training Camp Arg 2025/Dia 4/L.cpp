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

const ld PI = 3.14159265358979323846;

void solver(){
    int n, l, r; cin>>n>>l>>r;
    vector<int> x(n), y(n); vector<ld> b(n);
    for(int i = 0;  i < n; i++){
        int save;
        cin>>x[i]>>y[i]>>save;
        b[i] = (ld)save * PI / 180.0;
    }

    int lim = 1 << n;
    vector<ld> dp(lim, (ld)l);
    for(int mask = 1; mask < lim; mask++){
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))) continue;
            ld last = dp[mask ^ (1 << i)];
            ld num = sqrt((ld)y[i] * (ld)y[i] + ((ld)x[i] - last) * ((ld)x[i] - last)) * sin(b[i]), den;
            if(last < (ld)x[i]){
                den = sin(PI - atan((ld)y[i] / ((ld)x[i] - last)) - b[i]);
            }
            else{
                den = sin(atan((ld)y[i] / (last - (ld)x[i])) - b[i]);
            }

            if(last + ld(num / den) < last){
                cout<<fixed<<setprecision(10)<<(ld)(r - l)<<endl;
                return;
            }
            dp[mask] = max(dp[mask], last + (ld)(num / den));
        }
    }

    cout<<fixed<<setprecision(10)<<min((ld)r, dp[lim - 1]) - (ld)l<<endl;
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