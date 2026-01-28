#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 200005;
int components;
set<int> graph[maxn];
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
    int n; cin>>n;
    initDSU(n);
    for(int i = 1; i <= n; i++){
        int save; cin>>save;
        graph[i].insert(save);
        graph[save].insert(i);
        join(i, save);
    }

    int maxi = components;
    int unir = -1;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int u : sets[i]){
            if(graph[u].sz == 1) count++;
            if(count == 2){
                unir++;
                break;
            }
        }
    }

    unir = max(unir, 0);
    int mini = maxi - unir;
    cout<<mini<<' '<<maxi<<endl;

    for(int i = 1; i <= n; i++){
        sets[i].clear();
        graph[i].clear();
    }
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