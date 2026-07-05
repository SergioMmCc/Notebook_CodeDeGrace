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

vs ns;
map<string, int> sn;
void fillM(){
    vi aux;
    for(int i = 0; i < 26; i++) aux.pb(i+97);
    for(int i = 0; i < 26; i++) aux.pb(i+65);
    for(int i = 0; i < 10; i++) aux.pb(i+48);
 
    for(int x : aux){
        for(int y : aux){
            string add = "";
            add += (char)x;
            add += (char)y;
 
            sn[add] = sz(ns);
            ns.pb(add);
        }
    }
}

void DFS(int u, vector<vii>& graph, vb& used, vi& ans){
    while(!graph[u].empty()){
        pii edj = graph[u].back();
        int v = edj.fi, idx = edj.se;
        graph[u].pop_back(); // Eliminar arista ya visitada
        if(used[idx]) continue; // En caso de ya haber visitado esta arista partiendo desde v
        used[idx] = 1;
        DFS(v, graph, used, ans);
    }
    ans.pb(ns[u][1]);
}

void solver(){
    int n; cin>>n;
    vector<vii> graph(sz(ns));
    vi inDegree(sz(ns)), outDegree(sz(ns));
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        string u = ""; u += s[0]; u += s[1];
        string v = ""; v += s[1]; v += s[2];

        graph[sn[u]].pb({sn[v], i});
        outDegree[sn[u]]++;
        inDegree[sn[v]]++;
    }

    int u = -1, a = -1, b = -1; // a seria el nodo inicial y b el nodo final
    for(int i = 0; i < sz(ns); i++){
        if(outDegree[i] && u == -1) u = i;
        if(inDegree[i] > outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] == outDegree[i] + 1 && b == -1) b = i; // Este tendria que ser el nodo final
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(inDegree[i] < outDegree[i]){ // Si se quiere un ciclo, simplemente retornar que no se puede
            if(inDegree[i] + 1 == outDegree[i] && a == -1) a = i; // Este tendria que ser el nodo inicial
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    if((a >= 0 && b == -1) || (a == -1 && b >= 0)){ // Si solo hay nodo inicial o solo hay nodo final
        cout<<"NO"<<endl;
        return;
    }

    if(a == -1) a = u;

    vb used(n);
    vi ans;
    DFS(a, graph, used, ans); // Llamar a partir del nodo inicial (si lo hay)

    if(sz(ans) != n+1){ // En caso de que no todas las aristas estuvieran en el mismo componente
        cout<<"NO"<<endl;
        return;
    }

    ans.pb((int)ns[a][0]);
    reverse(all(ans));
    
    cout<<"YES"<<endl;
    for(int x : ans) cout<<(char)x;
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    fillM();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}