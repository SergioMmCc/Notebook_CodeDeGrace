#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    int d[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>d[i][j];
        }
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    stack<ll> ans;
    for(int kIndex = n-1; kIndex >= 0; kIndex--){
        int k = a[kIndex];
        ll total = 0;
        for(int iIndex = n-1; iIndex >= 0; iIndex--){
            int i = a[iIndex];
            for(int jIndex = n-1; jIndex >= 0; jIndex--){
                int j = a[jIndex];
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(iIndex >= kIndex && jIndex >= kIndex) total += d[i][j];
            }
        }

        ans.push(total);
    }

    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}