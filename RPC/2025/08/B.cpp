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

void solver(){
    int n, m, k; cin>>n>>m>>k;
    vector<vector<int>> travel(m+1);
    vector<int> ans(m+1);

    for(int i = 0; i < k; i++){
        int p, c; cin>>p>>c;
        travel[c].pb(p);
    }

    for(int i = 1; i <= m; i++){
        int ans = 0;
        for(int j = 1; j < travel[i].sz; j += 2){
            if(travel[i][j] == travel[i][j-1]) ans += 100;
            else ans += abs(travel[i][j] - travel[i][j-1]);
        }

        if(travel[i].sz % 2) ans += 100;

        cout<<ans;
        if(i < m) cout<<' ';
    }
    cout<<endl;
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