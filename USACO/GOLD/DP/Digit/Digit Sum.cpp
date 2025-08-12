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

ll dp[20][2][180];
vector<int> num;
int len;

void intToVec(ll x){
    num.clear();
    len = 0;

    for(int i = 0; i < 20; i++){
        num.pb(x % 10);
        len++;
        x /= 10;
    }

    reverse(num.begin(), num.end());
}

void reset(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 180; k++){
                dp[i][j][k] = -1;
            }
        }
    }
}

ll calc(int idx, bool under, int sum){
    if(idx == len) return sum;

    if(dp[idx][under][sum] != -1) return dp[idx][under][sum];

    int lim = under ? 9 : num[idx];
    ll ans = 0;

    for(int i = 0; i <= lim; i++){
        bool nUnder = under || i < num[idx];
        ans += calc(idx + 1, nUnder, sum + i);
    }

    dp[idx][under][sum] = ans;
    return ans;
}

ll solver(ll x){
    if(x <= 0) return 0;

    intToVec(x);
    reset();
    return calc(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll l, r; cin>>l>>r;
        cout<<solver(r) - solver(l-1)<<endl;
    }

    return 0;
}