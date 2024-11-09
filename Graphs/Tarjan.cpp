#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define pb push_back

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

const int MAXN = 1e5 + 1;
const ll mod = 1e9 + 7;

vector<int> g[MAXN];
vector<int> d(MAXN, -1), low(MAXN), scc(MAXN), reps(MAXN, 0);
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
    int n, m; cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u, v;cin>>u>>v;
        g[u].pb(v);
    }

    // Hallar los SCC
    for(int i = 1; i <= n; i++){
        if(d[i] == -1) 
            tarjan(i);
    }

    cout<<current_scc<<endl;
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