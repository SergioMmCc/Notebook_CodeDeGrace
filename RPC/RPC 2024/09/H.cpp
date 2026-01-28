#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

const int inf = 1e9;
int dpl[1002][10002], dpr[1002][10002], dup[1002][10002];

void solver(){
    int n, w; cin>>n>>w;
    vector<int> c(n+1), ans(n+1, inf);
    for(int i = 1; i <= n; i++)
        cin>>c[i];
    for(int k = 0; k <= n; k++)
        dpl[k][0] = dpr[k][0] = 0;
    for(int j = 1; j <= w; j++)
        dpl[0][j] = dpr[n+1][j] = dup[0][j] = inf;
    
    for(int j = 1; j <= w; j++){
        for(int k = 1; k <= n; k++){
            dpl[k][j] = dpl[k-1][j];
            if(c[k] > j)
                continue;
            dpl[k][j] = min(dpl[k][j], dpl[k][j - c[k]] + 1);
        }
    }
    for(int j = 1; j <= w; j++){
        for(int k = n; k > 0; k--){
            dpr[k][j] = dpr[k+1][j];
            if(c[k] > j)
                continue;
            dpr[k][j] = min(dpr[k][j], dpr[k][j - c[k]] + 1);
        }
    }
    for(int j = 1; j <= w; j++){
        for(int k = 1; k <= n; k++){
            dup[k][j] = dpl[k-1][j];
            if(2*c[k] > j)
                continue;
            dup[k][j] = min(dup[k][j], dup[k][j - 2*c[k]] + 1);
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= w; j++){
            ans[i] = min(ans[i], dup[i][j] + dpr[i + 1][w - j]);
        }
        ans[i] = min(ans[i], dpr[i+1][w]);
    }
    ans[n] = dup[n][w];
    
    for(int i = 1; i <= n; i++){
        if(i > 1)cout<<' ';
        if(ans[i] == inf)cout<<"impossible";
        else cout<<ans[i];
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