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

ll dp[20][41][2][2];
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
        for(int j = 0; j < 41; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll calc(int idx, int count, bool under, bool zero, int s1, int s2){
    // Tamano maximo
    if(idx == len){
        if(zero) return 0;
        if(s2 == -1) return count >= 20;
        else return count == 20;
    }

    // Ya fue calculado
    if(dp[idx][count][under][zero] != -1) return dp[idx][count][under][zero];

    int lim = (under ? 9 : num[idx]);
    ll ans = 0;
    for(int i = 0; i <= lim; i++){
        bool nUnder = (under || i < num[idx]);
        bool nZero = (zero && !i);
        if(!nZero && s2 != -1 && s2 != i && s1 != i) continue;
        int nCount;
        if(nZero) nCount = count;
        else nCount = (i == s1 ? count + 1 : count - 1);

        ans += calc(idx + 1, nCount, nUnder, nZero, s1, s2);
    }

    return dp[idx][count][under][zero] = ans;
}

ll solver(ll x){
    intToVec(x);
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        reset();
        ans += calc(0, 20, 0, 1, i, -1);
    }
    ll dup = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            reset();
            dup += calc(0, 20, 0, 1, i, j);
        }
    }

    ans -= dup / 2;

    return ans;
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);
    ll l, r; cin>>l>>r;
    cout<<solver(r) - solver(l-1)<<endl;

    return 0;
}