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

/*
    Construye un automata finito determinista que permite buscar patrones en un conjunto de palabras
    Complejidad O(m*k), siendo m la suma de longitudes de todas las cadenas y k el numero de caracteres en el alfabeto
*/

const int K = 16; // Cantidad de caracteres

// Vertices del trie
struct Vertex{
    int next[K]; // Vertice al que se llegaa siguiendo el caracter i, -1 si ninguno

    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1); // Se guarda el trie como un array de Vertex

// Agregar string al trie
// Complejidad: O(sz(s))
void add_vertex(int n, int a, string const& s, vector<vi>& tree){
    vb vis(n); vis[a] = 1;
    queue<pii> q;
    if(trie[0].next[s[a] - 'a'] == -1){
        trie[0].next[s[a] - 'a'] = sz(trie);
        q.push({a, sz(trie)});
        trie.emplace_back();
    }
    else q.push({a, trie[0].next[s[a] - 'a']});

    while(!q.empty()){
        int u = q.front().fi, ver = q.front().se; q.pop();
        for(int aux : tree[u]){
            if(vis[aux]) continue;
            vis[aux] = 1;
            int v = s[aux] - 'a';

            if(trie[ver].next[v] == -1){
                trie[ver].next[v] = sz(trie);
                q.push({aux, sz(trie)});
                trie.emplace_back();
            }
            else{
                q.push({aux, trie[ver].next[v]});
            }
        }
    }
}

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    for(int i = 0; i < n; i++) if((int)s[i] >= '0' && (int)s[i] <= '9') s[i] = 'g' - '0' + s[i];

    vector<vi> tree(n);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v; u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    for(int i = 0; i < n; i++) add_vertex(n, i, s, tree);
    cout<<sz(trie) - 1<<endl;
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