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

const int maxn = 1e6 + 1;
int components;
vector<int> leader(maxn);
vector<int> sets[maxn];

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        for(int i = 0; i < sets[leaderV].size(); i++){
            int v = sets[leaderV][i];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
        }
        sets[leaderV].clear();
        components--;
    }
}

void solver(){
    int n, m; cin>>n>>m;
    vector<int> index(n+1);
    for(int i = 1; i <= n; i++) cin>>index[i];
    initDSU(n);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        join(u, v);
    }

    for(int i = 1; i <= n; i++){
        sets[leader[i]].pop_back();
    }

    for(int i = 1; i <= n; i++){
        sets[leader[i]].push_back(index[i]);
    }

    for(int i = 1; i <= n; i++){
        if(i == leader[i]) sort(sets[i].begin(), sets[i].end());
    }

    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        int lid = leader[i];
        ans[i] = sets[lid][sets[lid].sz - 1];
        sets[lid].pop_back();
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<' '; cout<<endl;
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