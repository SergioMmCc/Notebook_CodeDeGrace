#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 200005;
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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m;cin>>n>>m;
    initDSU(n); //Inicializar DSU
    for(int i = 0; i < m; i++){
        int u, v;cin>>u>>v;
        join(u, v); //Unir vertice u con v
    }
    cout<<components<<endl;

    return 0;
}