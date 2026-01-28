#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
const int mod = 998244353;

void solver(){
    int n; cin>>n;
    vector<int> level(n+1);
    vector<vector<int>> levels(n);
    vector<vector<int>> sons(n+1);
    vector<int> ansVertex(n+1), ansLevel(n+1);
    int lastLevel = 0;
    for(int i = 2; i <= n; i++){
        int parent; cin>>parent;
        level[i] = level[parent] + 1;
        levels[level[i]].pb(i);
        sons[parent].pb(i);
        lastLevel = max(lastLevel, level[i]);
    }

    for(int i = lastLevel; i > 0; i--){
        // cout<<"level -> "<<i<<endl;
        for(int u : levels[i]){
            // cout<<"u -> "<<u<<endl;
            ansVertex[u] = (1 + ansLevel[i+1]) % mod;
            for(int k : sons[u]){
                ansVertex[u] -= ansVertex[k];
                ansVertex[u] = (ansVertex[u] + mod) % mod;
            }
            ansLevel[i] += ansVertex[u] % mod;
            ansLevel[i] %= mod;
        }
    }

    int ans = (1 + ansLevel[1]) % mod;
    cout<<ans<<endl;
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