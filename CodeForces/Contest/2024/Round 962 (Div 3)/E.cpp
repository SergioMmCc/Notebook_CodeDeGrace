#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int const mod = 1e9 + 7;

void solver() {
    string str;cin>>str;
    int n = str.size();
    long long ans = 0;
    vector<int> P(n+1);
    vector<long long> Q(2*n + 2, 0);
    P[0] = 0;
    
    for(int i = 0; i < n; i++) 
        P[i+1] = P[i] + (str[i] == '1' ? 1 : -1);
    
    for(int i = 1; i <= n; i++) {
        Q[P[i-1] + n] += i;
        ans = (ans + (Q[P[i] + n] * (n-i+1))) % mod;
    }
    
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}