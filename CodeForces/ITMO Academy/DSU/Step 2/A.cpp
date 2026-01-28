#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1000005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn), maxMember(maxn);
vector<int> sets[maxn];

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        maxMember[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        int newMax = max(maxMember[leaderU], maxMember[leaderV]);
        maxMember[leaderU] = maxMember[leaderV] = newMax;
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
    int n, q; cin>>n>>q;
    initDSU(n+1);
    while(q--){
        char op; int u; cin>>op>>u;
        if(op == '?') cout<<(maxMember[leader[u]] == n+1 ? -1 : maxMember[leader[u]])<<endl;
        else{
            int v = maxMember[leader[u]] + 1;
            if(v > n+1) continue;
            join(u, v);
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