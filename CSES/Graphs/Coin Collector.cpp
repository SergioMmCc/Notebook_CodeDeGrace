#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void tarjan(int u, vector<vi>& graph, vi&d, vi& low, vi& scc, vi& reps, vb& stacked, stack<int>& s, int& ticks, int& current_scc){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vi &out = graph[u];
    for(int k=0, m=out.size(); k<m; ++k){
        const int &v = out[k];
        if(d[v] == -1){
            tarjan(v, graph, d, low, scc, reps, stacked, s, ticks, current_scc);
            low[u] = min(low[u], low[v]);
        }
        else if(stacked[v])
            low[u] = min(low[u], low[v]);
    }
    if(d[u] == low[u]){
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

ll topoSort(int n, vi& inDegree, vector<set<int>>& graph, vl& c2){
    vl best(n+1);
    queue<int> q;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!inDegree[i]){
            best[i] = c2[i];
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        ans = max(ans, best[u]);
        for(int v : graph[u]){
            best[v] = max(best[v], best[u] + c2[v]);
            inDegree[v]--; // Quitamos un inDegree a cada vertice que puede ser visitado desde otro ya procesado
            if(!inDegree[v]){
                q.push(v);
            }
        }
    }

    return ans;
}

void solver(){
    int n, m; cin>>n>>m;

    vector<vi> graph(n+1);
    vi d(n+1, -1), low(n+1), scc(n+1), reps(n+1, 0);
    vb stacked(n+1);
    stack<int> s;
    int ticks = 0, current_scc = 0;

    vl c(n+1);
    for(int i = 1; i <= n; i++) cin>>c[i];
    for(int i = 1; i <= m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
    }

    for(int i = 1; i <= n; i++) if(d[i] == -1) tarjan(i, graph, d, low, scc, reps, stacked, s, ticks, current_scc);

    vl c2(current_scc+1);
    vector<set<int>> graph2(current_scc+1);
    vi inDegree(current_scc+1);
    for(int i = 1; i <= n; i++){
        c2[scc[i]+1] += c[i];
        for(int v : graph[i]){
            if(scc[v] != scc[i] && graph2[scc[i]+1].find(scc[v]+1) == graph2[scc[i]+1].end()){
                graph2[scc[i]+1].insert(scc[v]+1);
                inDegree[scc[v]+1]++;
            }
        }
    }

    cout<<topoSort(current_scc, inDegree, graph2, c2)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}