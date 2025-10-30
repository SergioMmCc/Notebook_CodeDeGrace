#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 300005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn), nextMember(maxn);
vector<int> sets[maxn];

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        nextMember[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v, int n){
    if(v > n) v = 1;
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        int nextM = nextMember[leader[v]];
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        nextMember[leaderU] = nextM;
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
    int n; cin>>n;
    initDSU(n);
    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        int save; cin>>save;
        cout<<nextMember[leader[save]];
        join(save, nextMember[leader[save]] + 1, n);
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