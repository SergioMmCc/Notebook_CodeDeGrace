#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 200005;
int components;
vector<int> leader(maxn);
vector<int> sets[maxn];
vector<int> ans(maxn, -2);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v, int index){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        if(leaderV == 1) swap(leaderU, leaderV);
        for(int i = 0; i < sets[leaderV].size(); i++){
            int v = sets[leaderV][i];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
            ans[v] = index;
        }
        sets[leaderV].clear();
        components--;
    }
}

void solver(){
    ans[1] = -1;
    int n, m; cin>>n>>m;
    initDSU(n);
    map<piii, bool> edges;
    map<pii, int> translate;
    for(int i = 1; i <= n; i++){
        int a, b; cin>>a>>b;
        if(a != -1){
            edges[{{i, a}, 1}] = 0;
            translate[{i, 1}] = a;
        }
        if(b != -1){
            edges[{{i, b}, 2}] = 0;
            translate[{i, 2}] = b;
        }
    }

    vector<pii> take(m);
    for(int i = 0; i < m; i++){
        int u, s; cin>>u>>s;
        int v = translate[{u, s}];
        edges[{{u, v}, s}] = 1;
        take[i] = {min(u, v), max(u, v)};
    }

    for(const auto& edge : edges){
        if(edge.second) continue;
        int u = edge.first.first.first, v = edge.first.first.second;
        // cout<<"u -> "<<u<<" v -> "<<v<<endl;
        join(min(u, v), max(u, v), -1);
    }
    cout<<endl;
    for(int i = m - 1; i >= 0; i--){
        int u = min(take[i].first, take[i].second);
        int v = max(take[i].first, take[i].second);
        // cout<<"join: u -> "<<u<<" v -> "<<v<<endl;
        join(u, v, i);
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<endl;
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