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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void topoSort(int n, vi& orden, vi& inDegree, vector<vi>& graph){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!inDegree[i]){ 
            // Si el nodo no tiene ningun inDegree, quiere decir que puede ir al incio del topoSort
            q.push(i);
            orden.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            inDegree[v]--; // Quitamos un inDegree a cada vertice que puede ser visitado desde otro ya procesado
            if(!inDegree[v]){ 
                // Si su inDegree ahora es 0, quiere decir que ya fueron procesados todos los nodos que lo 
                // anteceden, por ende ahora puede ser agregado al topoSort, y lo metemos a la cola
                q.push(v);
                orden.pb(v);
            }
        }
    }
}

void solver(){
    int n; cin>>n;
    vs a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> graph(26);
    vi inDegree(26);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int k = 0;
            while(k < sz(a[i]) && k < sz(a[j])){
                if(a[i][k] != a[j][k]){
                    graph[a[i][k] - 'a'].pb(a[j][k] - 'a');
                    inDegree[a[j][k] - 'a']++;
                    break;
                }

                k++;
                if(sz(a[i]) == k) break;
                if(sz(a[j]) == k){
                    cout<<"Impossible"<<endl;
                    return;
                }
            }
        }
    }

    vi orden;
    topoSort(26, orden, inDegree, graph);
    if(sz(orden) != 26){
        cout<<"Impossible"<<endl;
        return;
    }

    for(int x : orden) cout<<(char)(x + 'a');
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