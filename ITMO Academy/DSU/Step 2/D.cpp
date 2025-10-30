#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 300005;
vector<int> leader(maxn), sizen(maxn), jefes(maxn);

void initDSU(int n){
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
        jefes[i] = 0;
    }
}

pii find(int u){
    if(leader[u] != u){
        pii v = find(leader[u]);
        leader[u] = v.first;
        jefes[u] += v.second;
    }
    return {leader[u], jefes[u]};
}

void join(int u, int v){
    int leaderU = find(u).first, leaderV = find(v).first;
    if(leaderU != leaderV){
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        jefes[v] = 1;
    }
}

void solver(){
    int n, m; cin>>n>>m;
    initDSU(n);
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int u, v; cin>>u>>v;
            join(v, u);
        }
        else{
            int u; cin>>u;
            find(u);
            cout<<jefes[u]<<endl;
        }
    }
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