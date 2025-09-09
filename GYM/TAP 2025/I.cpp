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
    int n, m; cin>>n>>m;
    vector<int> ans(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin>>x>>y;
        vector<int> c(n+1, 1);
        int count = 0;
        for(int i = 0; i < n; i++){
            cin>>c[i];
            if(c[i] == 1) count++;
        }

        int div = x / (count + 1);
        if(div < y){
            if(count) div = x / count;
            c[n] = 2;
        }

        for(int i = 0; i <= n; i++) ans[i] += c[i] == 1 ? div : y;
    }

    for(int i = 0; i <= n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
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