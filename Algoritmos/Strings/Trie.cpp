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

const int K = 26; // Cantidad de caracteres

// Vertices del trie
struct Vertex{
    int next[K]; // Vertice al que se llegaa siguiendo el caracter i, -1 si ninguno
    bool output = 0; // 1 si el vertice corresponde a un array en el diccionario

    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1); // Se guarda el trie como un array de Vertex

// Agregar string al trie
// Complejidad: O(sz(s))
void add_string(string const& s){
    int v = 0; // Se inicia en el nodo raiz
    for(char ch : s){ // Se recorre el trie con la palabra a agregar
        int c = ch - 'a'; // Se toma 'a' como primer caracter del alfabeto
        if(trie[v].next[c] == -1){ // Si no hay un vertice correspondiendo al siguiente caracter, se agrega
            trie[v].next[c] = sz(trie);
            trie.emplace_back();
        }
        v = trie[v].next[c]; // Se avanza al siguiente vertice
    }
    trie[v].output = 1; // Marca la flag del vertice de salida
}

void solver(){
    
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