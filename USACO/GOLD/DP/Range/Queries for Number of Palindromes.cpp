#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = __int128;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int  N = 5001;
int dp[N][N];
const ll m = 2305843009213693951;

// Sirve para hacer precalculos para hacer queries de la subcadena
// sl, sl+1, ..., sr
// Construir el array toma O(n), las queires son O(1)
void precalc_hashing(string s, vector<ll>& h, vector<ll>& ph){
    ll p = 31;

    h[0] = s[0] - 'a' + 1;
    ph[0] = 1;

    for(int i = 1; i < s.sz; i++){
        h[i] = (((h[i-1] * p) % m) + (s[i] - 'a' + 1)) % m;
        ph[i] = (ph[i-1] * p) % m;
    }

    /* 
        Para hacer queries:
        - Si l = 0: h[r]
        - Si no: (h[r] - h[l-1] * ph[r-l+1]) % m
    */
}

ll queries(ll l, ll r, vector<ll>& h, vector<ll>& ph){
    if(!l) return h[r];
    return (h[r] - ((h[l-1] * ph[r-l+1]) % m) + m) % m;
}

void solver(){
    string s2; cin>>s2;
    string s1 = s2;
    reverse(s2.begin(), s2.end());
    int n = s1.sz;
    vector<ll> h1(n), ph1(n), h2(n), ph2(n);
    precalc_hashing(s1, h1, ph1);
    precalc_hashing(s2, h2, ph2);

    // Calcular DP
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            if(queries(i, j, h1, ph1) == queries(n - j - 1, n - i - 1, h2, ph2)) dp[i][j]++;
        }
    }

    // Responder queries
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r; l--; r--;
        cout<<dp[l][r]<<endl;
    }
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