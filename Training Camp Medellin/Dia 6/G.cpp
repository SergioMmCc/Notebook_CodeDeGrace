#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int INF=1E9, MOD=1E9+7;


void solve(){
    int n; 
    cin>>n;
    vector<vector<int>> vec(2, vector<int>(n));
    for(int i=0; i<n; i++)cin>>vec[0][i];
    for(int i=0; i<n; i++)cin>>vec[1][i];

    map<int, int> pA, pB;
    for(int i=0; i<n; i++){
        pA[vec[0][i]] = i;
        pB[vec[1][i]] = i;
        if(vec[0][i] == vec[1][i]){
            cout<<"0\n";
            return;
        }
    }

    vector<int> vis(n);
    ll c=1;
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        int x=i;
        while(!vis[x]){
            //cout<<x<<"["<<vec[0][x]<<"] -> "<<pB[vec[0][x]]<<"["<<vec[1][pB[vec[0][x]]]<<"] \n";
            vis[x] = 1;
            x = vec[0][x];
            x = pB[x];
        }
        c *= 2;
        c %= MOD;
    }

    cout<<c<<"\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}