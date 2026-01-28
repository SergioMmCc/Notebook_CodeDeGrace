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

const int maxn = 5000, inf = 1e9;

void solver(){
    int n; cin>>n;
    vector<int> a(n), dp(maxn + 1, inf);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        dp[a[i]] = 0;
    }

    int totalGCD = a[0];
    for(int i = 1; i < n; i++) totalGCD = __gcd(totalGCD, a[i]);

    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == totalGCD) count++;
    }

    if(count){
        cout<<n - count<<endl;
        return;
    }

    for(int i = maxn; i > 0; i--){
        for(int j = 0; j < n; j++){
            int calc = __gcd(i, a[j]);
            dp[calc] = min(dp[calc], dp[i] + 1);
        }
    }

    cout<<dp[totalGCD] + n - 1<<endl;
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