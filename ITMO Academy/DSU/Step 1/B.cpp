#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<vector<int>, pii> pvii;

const int maxn = 3e5 + 2;
vector<int> leader(maxn);
pvii sets[maxn];
int components;

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].first.push_back(i);
        sets[i].second.first = i;
        sets[i].second.second = i;
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].first.size() > sets[leaderU].first.size())
            swap(leaderU, leaderV);
        
        for(int i = 0; i < sets[leaderV].first.size(); i++){
            int v = sets[leaderV].first[i];
            leader[v] = leaderU;
            sets[leaderU].first.push_back(v);
            if(v < sets[leaderU].second.first) sets[leaderU].second.first = v;
            if(v > sets[leaderU].second.second) sets[leaderU].second.second = v;
        }
        sets[leaderV].first.clear();
        components--;
    }
}

void solver(){
    int n, q; cin>>n>>q;
    initDSU(n);
    while(q--){
        string op; int u, v; cin>>op;
        if(op == "union"){
            cin>>u>>v;
            join(u, v);
        }
        else{
            cin>>v;
            cout<<sets[leader[v]].second.first<<' '<<sets[leader[v]].second.second<<' '<<sets[leader[v]].first.sz<<endl;
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