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
    for(int i = 1; i <= n; i++){
        int save; 
        cin>>save;
    }

    int m; cin>>m;
    vector<int> d(n+1, inf);
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        d[v] = min(d[v], w);
    }

    int ans = 0;
    bool cond = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == inf){
            if(!cond) cond = 1;
            else{
                cout<<-1<<endl;
                return;
            }
        }

        else ans += d[i];
    }

    cout<<ans<<endl;
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