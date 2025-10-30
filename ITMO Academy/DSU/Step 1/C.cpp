#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 200005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn), value(maxn);
vector<int> sets[maxn];

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        value[i] = 0;
        sets[i].push_back(i);
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        int lastValue = value[leaderV];
        for(int i = 0; i < sets[leaderV].size(); i++){
            int v = sets[leaderV][i];
            if(leader[v] != v) value[v] += lastValue;
            value[v] = value[v] - value[leaderU];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
        }
        sets[leaderV].clear();
        components--;
    }
}

void solver(){
    int n, q; cin>>n>>q;
    initDSU(n);
    while(q--){
        string op; cin>>op;
        if(op == "join"){
            int u, v; cin>>u>>v;
            join(u, v);
        }
        else if(op == "add"){
            int u, v; cin>>u>>v;
            value[leader[u]] += v;
        }
        else{
            int u; cin>>u;
            cout<<(leader[u] == u ? value[u] : value[leader[u]] + value[u])<<endl;
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