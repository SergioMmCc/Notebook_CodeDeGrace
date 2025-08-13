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

const int inf = 1e9 + 1;

void solver(){
    int n; cin>>n;
    vector<int> dp(n+1, inf); dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int aux = i;
        while(aux){
            dp[i] = min(dp[i], dp[i - (aux % 10)] + 1);
            aux /= 10;
        }
    }

    cout<<dp[n]<<endl;
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