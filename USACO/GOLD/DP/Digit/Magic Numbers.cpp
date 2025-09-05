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

const ll mod = 1e9 + 7;
int d, m, len;
vector<int> num;

ll dp[2001][2][2000];

void strToVec(string x){
    num.clear();
    len = x.sz;
    for(int i = 0; i < len; i++){
        num.pb(x[i] - '0');
    }
}

void rest(){
    bool cond = 0;
    for(int i = len - 1; !cond && i >= 0; i--){
        if(num[i]){
            num[i]--;
            cond = 1;
        }
        else num[i] = 9;
    }
}

ll calc(int idx, bool under, int res){
    if(idx == len) return !res ? 1 : 0;

    if(dp[idx][under][res] != -1) return dp[idx][under][res];

    ll ans = 0;
    if(idx % 2){
        if(!under && num[idx] < d) return 0;
        bool nUnder = under || num[idx] > d;
        int nRes = (10*res + d) % m;
        ans = calc(idx + 1, nUnder, nRes);
    }

    else{
        int lim = under ? 9 : num[idx];
        for(int i = 0; i <= lim; i++){
            if(i == d) continue;
            bool nUnder = under || num[idx] > i;
            int nRes = (10*res + i) % m;
            ans = (ans + calc(idx+1, nUnder, nRes)) % mod;
        }
    }

    return dp[idx][under][res] = ans;
}

void reset(){
    for(int i = 0; i < 2001; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2000; k++){
                dp[i][j][k] = -1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>m>>d;
    string a, b; cin>>a>>b;

    reset();
    strToVec(b);
    ll ans = calc(0, 0, 0);
    
    reset();
    strToVec(a);
    rest();
    ll aux = calc(0, 0, 0);
    
    ans = (ans - aux + mod) % mod;
    cout<<ans<<endl;

    return 0;
}