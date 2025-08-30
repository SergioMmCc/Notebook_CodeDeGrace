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

ll dp[20][2][2][10];
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
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 10; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll calc(int idx, bool under, bool zero, int last){
    if(idx == len) return 1;

    if(dp[idx][under][zero][last] != -1) return dp[idx][under][zero][last];

    int lim = under ? 9 : num[idx];
    ll ans = 0;

    for(int i = 0; i <= lim; i++){
        bool nUnder = under || i < num[idx];
        bool nZero = zero || i;
        if(i == last && (i || nZero)) continue;
        ans += calc(idx+1, nUnder, nZero, i);
    }

    return dp[idx][under][zero][last] = ans;
}

ll solver(ll x){
    if(x == -1) return 0;
    reset();
    intToVec(x);
    return calc(0, 0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll a, b; cin>>a>>b;
    cout<<solver(b) - solver(a - 1)<<endl;

    return 0;
}