#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
#define int long long

void solver(){
    int n, m; cin>>n>>m;
    ll matriz[n][m], prefixSum[n][m];
    vector<pair<ll, int>> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        ll firstValue = 0;
        for(int j = 0; j < m; j++){
            cin>>matriz[i][j];
            if(j) prefixSum[i][j] = matriz[i][j] + prefixSum[i][j-1];
            else prefixSum[i][j] = matriz[i][j];
            firstValue += prefixSum[i][j];
            if(j == m-1){
                a[i] = {prefixSum[i][j], i};
                b[i] = firstValue;
            }
        }
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int index = a[i].second;
        ll sumTotal = a[i].first;
        ans += b[index] + sumTotal * (ll)m * (ll)i;
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}