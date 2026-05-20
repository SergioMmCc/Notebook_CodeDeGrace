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
    ans.pb((int)ns[u][1]);
}

void solver(){
    vector<vii> graph(sz(ns));
    vi inDegree(sz(ns)), outDegree(sz(ns));
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        string aux; cin>>aux;
        string u = ""; u += aux[0]; u += aux[1];
        string v = ""; v += aux[1]; v += aux[2];

        graph[sn[u]].pb({sn[v], i});
        outDegree[sn[u]]++;
        inDegree[sn[v]]++;
    }

    int u = -1, a = -1, b = -1;
    for(int i = 0; i < sz(ns); i++){
        if(outDegree[i] && u == -1) u = i;
        if(inDegree[i] - outDegree[i] > 0){
            if(inDegree[i] - outDegree[i] > 1 || a != -1){
                cout<<"NO"<<endl;
                return;
            }
            else a = i;
        }
        else if(outDegree[i] - inDegree[i] > 0){
            if(outDegree[i] - inDegree[i] > 1 || b != -1){
                cout<<"NO"<<endl;
                return;
            }
            else b = i;
        }
    }

    if(b == -1) b = u;

    vb used(n);
    vi ans;
    DFS(b, graph, used, ans);
    if(sz(ans) != n+1){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    ans.pb((int)ns[b][0]);
    reverse(all(ans));
    for(int i = 0; i < sz(ans); i++) cout<<(char)ans[i];
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