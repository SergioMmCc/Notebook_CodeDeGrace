#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define pb push_back

const int MAXN = 1e5 + 1;
const ll mod = 1e9 + 7;

vector<int> g[MAXN];
vector<int> d(MAXN, -1), low(MAXN), scc(MAXN), reps(MAXN, 0);
vector<ll> cost(MAXN), mini(MAXN, 2e9);
vector<bool> stacked(MAXN);
stack<int> s;
int ticks = 0, current_scc = 0;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for (int k=0, m=out.size(); k<m; ++k){
        const int &v = out[k];
        if (d[v] == -1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (stacked[v])
            low[u] = min(low[u], low[v]);
    }
    if (d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        }while (u != v);
        current_scc++;
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++)cin>>cost[i];
    int m; cin>>m;
    for(int i = 1; i <= m; i++){
        int u, v;cin>>u>>v;
        g[u].pb(v);
    }

    for(int i = 1; i <= n; i++){
        if(d[i] == -1) 
            tarjan(i);
    }

    for(int i = 1; i <= n; i++){
        int c = scc[i];
        if(cost[i] < mini[c]) {mini[c] = cost[i]; reps[c] = 1;}
        else if(cost[i] == mini[c]) reps[c]++;
    }

    ll a = 0, b = 1;
    for(int i = 0; i < current_scc; i++){
        a += mini[i];
        b *= reps[i];
        b %= mod;
    }

    cout<<a<<' '<<b<<endl;
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