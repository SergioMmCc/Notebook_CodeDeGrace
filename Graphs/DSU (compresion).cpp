#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 200005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn), sizen(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(leaderU != leaderV){
        if(sizen[leaderV] > sizen[leaderU])
            swap(leaderU, leaderV);
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        components--;
    }
}

void updateAllLeaders(int n){
    for(int i = 1; i <= n; i++)
        find(i);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m;cin>>n>>m;
    initDSU(n); //Inicializar DSU
    for(int i = 0; i < m; i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        join(u, v); //Unir vertice u con v
    }

    updateAllLeaders(n);
    for(int i = 1; i <= n; i++)
        cout<<"Lider de "<<i<<" -> "<<leader[i]<<endl;
    cout<<components<<endl;

    return 0;
}