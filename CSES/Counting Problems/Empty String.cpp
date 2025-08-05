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

const int N = 501;
const ll mod = 1e9 + 7;
ll dp[N][N];
ll binom[N][N];

void calcBinom(){
    for(int i = 0; i < N; i++) binom[i][0] = binom[i][i] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j < i; j++){
            binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }
}

void solver(){
    string s; cin>>s;
    int n = s.sz;
    if(n % 2){
        cout<<0<<endl;
        return;
    }

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) dp[i-1][i] = 1;
    }

    for(int len = 4; len <= n; len += 2){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            for(int k = i + 1; k <= j; k += 2){
                if(s[i] != s[k]) continue;

                ll num = binom[len / 2][(k - i + 1) / 2];

                ll l;
                if(k == i+1) l = 1;
                else l = dp[i+1][k-1];

                ll r;
                if(k == j) r = 1;
                else r = dp[k+1][j];

                num *= (l * r) % mod;
                num %= mod;
                dp[i][j] += num;
                dp[i][j] %= mod;
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcBinom();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}