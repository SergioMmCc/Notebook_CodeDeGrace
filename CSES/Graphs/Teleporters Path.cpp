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

void DFS(int u, vector<vii>& graph, vb& used, vi& ans){
    while(!graph[u].empty()){
        pii edj = graph[u].back();
        int v = edj.fi, idx = edj.se;
        graph[u].pop_back(); // Eliminar arista ya visitada
        if(used[idx]) continue; // En caso de ya haber visitado esta arista partiendo desde v
        used[idx] = 1;
        DFS(v, graph, used, ans);
    }
    ans.pb(u);
}

void solver(){
    int n, m; cin>>n>>m;
    vector<vii> graph(n+1);
    vi inDegree(n+1), outDegree(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].pb({v, i});
        outDegree[u]++;
        inDegree[v]++;
    }

    // Revision para grafos dirigidos
    int a = 0, b = 0; // a seria el nodo inicial y b el nodo final
    for(int i = 1; i <= n; i++){
        if(inDegree[i] > outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] == outDegree[i] + 1 && !b) b = i; // Este tendria que ser el nodo final
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
        else if(inDegree[i] < outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] + 1 == outDegree[i] && !a) a = i; // Este tendria que ser el nodo inicial
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    if(a != 1 || b != n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    if((a && !b) || (!a && b)){ // Si solo hay nodo inicial o solo hay nodo final
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vb used(m+1);
    vi ans;
    DFS((!a ? 1 : a), graph, used, ans); // Llamar a partir del nodo inicial (si lo hay)

    if(sz(ans) != m+1){ // En caso de que no todas las aristas estuvieran en el mismo componente
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    reverse(all(ans));

    for(int x : ans) cout<<x<<' ';
    cout<<endl;
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