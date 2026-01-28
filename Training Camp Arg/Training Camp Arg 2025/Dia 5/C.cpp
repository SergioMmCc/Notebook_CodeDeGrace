#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

/* Complexity: O(E + V)
Tarjan’s algorithm for finding strongly connected
components.
*d[i] = Discovery time of node i. (Initialize to -1)
*low[i] = Lowest discovery time reachable from node
i. (Doesn’t need to be initialized)
*scc[i] = Strongly connected component of node i. (Doesn’t
need to be initialized) (0-index)
*s = Stack used by the algorithm (Initialize to an empty
stack)
*stacked[i] = True if i was pushed into s. (Initialize to
false)
*ticks = Clock used for discovery times (Initialize to 0)
*current_scc = ID of the current_scc being discovered
(Initialize to 0)
*/

const int maxn = 1e6 + 1;

vector<int> graph[maxn];
vector<int> d(maxn, -1), low(maxn), scc(maxn), reps(maxn, 0);
vector<bool> stacked(maxn);
stack<int> s;
int ticks = 0, current_scc = 0;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = graph[u];
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
    int n, m; cin>>n>>m;

    // Limpiar caso anterior
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        d[i] = -1;
        low[i] = 0;
        scc[i] = 0;
        reps[i] = 0;
        stacked[i] = 0;
    }
    while(!s.empty()) s.pop();
    ticks = 0;
    current_scc = 0;

    for(int i = 1; i <= m; i++){
        int u, v;cin>>u>>v;
        if(u == v) continue;
        graph[u].pb(v);
    }

    // Hallar los SCC
    for(int i = 1; i <= n; i++){
        if(d[i] == -1) 
            tarjan(i);
    }

    if(current_scc == 1){
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    vector<bool> pos(current_scc, 1);
    for(int i = 1; i <= n; i++){
        for(int v : graph[i]){
            if(scc[v] != scc[i]) pos[scc[v]] = 0;
        }
    }

    int choose = -1;
    for(int i = 0; choose == -1 && i < current_scc; i++){
        if(pos[i]) choose = i;
    }

    vector<int> g, j;
    for(int i = 1; i <= n; i++){
        if(scc[i] == choose) g.pb(i);
        else j.pb(i);
    }

    cout<<j.sz<<' '<<g.sz<<endl;
    for(int aux : j) cout<<aux<<' '; cout<<endl;
    for(int aux : g) cout<<aux<<' '; cout<<endl;
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