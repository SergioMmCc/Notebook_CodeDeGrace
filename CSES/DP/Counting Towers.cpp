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

const int mod = 1e9 + 7;
const int maxn = 1e6 + 1;
vector<int> d(maxn), s(maxn);

void calc(){
    d[1] = 1; s[1] = 1;
    for(int i = 2; i < maxn; i++){
        d[i] = (2 * d[i-1]) % mod;
        d[i] = (d[i] + s[i-1]) % mod;
        
        s[i] = (2 * s[i-1]) % mod;
        s[i] = (2 * s[i]) % mod;
        s[i] = (s[i] + d[i-1]) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calc();
    int t = 1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<(d[n] + s[n]) % mod<<endl;
    }

    return 0;
}