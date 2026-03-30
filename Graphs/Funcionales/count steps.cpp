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
    Sirve para hallar cuantos pasos hay que dar desde un nodo a hasta un nodo b.
    Complejidad: O(n * log(n))
    - isCicle marca si un nodo hace parte de un ciclo o no
    - liderCicle guarda el lider de cada ciclo
    - stCicle guarda la distancia desde un nodo de un ciclo hasta su lider
    - lenCicle dice la distancia del ciclo del cual un nodo es lider
    - distCicle guarda la distancia de un nodo cualquiera a un ciclo
    - whereCicle guarda cpara cada nodo fuera de un ciclo cual es el primer ciclo al cual llega
*/

int LOG_N = 18; // techo del log2 del maximo valor de k que me puedan dar en las queries
const int maxn = 2e5 + 1;
int n;
vi func(maxn), liderCicle(maxn), stCicle(maxn), lenCicle(maxn), distCicle(maxn), whereCicle(maxn);
vb vis(maxn), isCicle(maxn);
vector<vi> succ(LOG_N, vi(maxn));

// Se usa para verificar aquellas queries donde a y b no hacen parte de ciclo
void calcSucc(){
    for(int i = 1; i <= n; i++) succ[0][i] = func[i];
    for(int bit = 1; bit < LOG_N; bit++){
        for(int i = 1; i <= n; i++){
            succ[bit][i] = succ[bit-1][succ[bit-1][i]];
        }
    }
}

int kSucc(int s, int k){
    for(int bit = 0; bit < LOG_N; bit++){
        if(k & (1 << bit)) s = succ[bit][s];
    }

    return s;
}

// Precalcula isCicle, liderCicle, stCicle y lenCicle
void floyd(int x){
    vis[x] = 1;
    int a = func[x];
    int b = func[func[x]];

    while(a != b){
        if(vis[a]) return; // Saltar en caso de que ya haya calculado esta rama desde un nodo inferior
        vis[a] = 1; // Marcar los nodos externos a un ciclo que ya han sido visitados
        a = func[a];
        b = func[func[b]];
    }

    a = x;
    while(a != b){
        a = func[a];
        b = func[b];
    }

    int lider = b;
    liderCicle[lider] = b; // Se guarda el lider
    isCicle[b] = 1;
    lenCicle[b] = 1;
    int last = 0;
    vis[lider] = 1;
    b = func[b];
    while(a != b){
        liderCicle[b] = lider;
        lenCicle[lider]++; // Al llegar a otro nodo se aumenta la longitud del ciclo
        last++;
        stCicle[b] = last;
        isCicle[b] = 1;
        vis[b] = 1; // Se marcan como visitados todos los nodos del ciclo
        b = func[b];
    }
}

// Precalcula whereCicle y distCicle para los nodos fuera de un ciclo
void DFS(int u){
    int v = func[u];
    if(isCicle[v]){
        whereCicle[u] = v;
        distCicle[u] = 1;
    }
    else if(distCicle[v]){
        whereCicle[u] = whereCicle[v];
        distCicle[u] = distCicle[v] + 1;
    }
    else{
        DFS(v);
        whereCicle[u] = whereCicle[v];
        distCicle[u] = distCicle[v] + 1;
    }
}

void solver(){
    int q; cin>>n>>q;
    vi inDegree(n+1);
    for(int i = 1; i <= n; i++){
        cin>>func[i];
        inDegree[func[i]]++;
    }
    calcSucc();

    for(int i = 1; i <= n; i++) if(!vis[i]) floyd(i);

    for(int i = 1; i <= n; i++){
        if(inDegree[i]) continue;
        DFS(i);
    }

    while(q--){
        int a, b; cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
            continue;
        }

        // Si ambos son parte de un ciclo primero se verifica si es el mismo y luego se calcula la distancia usando stCicle
        if(isCicle[a] && isCicle[b]){
            if(liderCicle[a] != liderCicle[b]) cout<<-1<<endl;
            else cout<<(stCicle[b] - stCicle[a] + lenCicle[liderCicle[a]]) % lenCicle[liderCicle[a]]<<endl;
        }

        // Si ninguno hace parte de ciclo se verifica si hacen parte de la misma rama (usando whereCicle), despues se usa
        // distCicle para calcular dif (a que distancia deberia estar a de b) y si es positiva se usa kSucc para verificar que
        // al dar dif pasos desde a se llega hasta b
        else if(!isCicle[a] && !isCicle[b]){
            if(whereCicle[a] != whereCicle[b]) cout<<-1<<endl;
            else{
                int dif = distCicle[a] - distCicle[b];
                if(dif <= 0) cout<<-1<<endl;
                else{
                    if(kSucc(a, dif) == b) cout<<dif<<endl;
                    else cout<<-1<<endl;
                }
            }
        }

        // Si a no esta en ciclo pero b si, se revisa si a llega al mismo ciclo que b (usando whereCicle) y en caso de que si se
        // suma la distancia de a hasta un ciclo y se usa whereCicle[a] y stCicle para calcular cuanto se tarda desde whereCicle[a] hasta b
        else if(!isCicle[a] && isCicle[b]){
            if(liderCicle[whereCicle[a]] != liderCicle[b]) cout<<-1<<endl;
            else cout<<distCicle[a] + ((stCicle[b] - stCicle[whereCicle[a]] + lenCicle[liderCicle[b]]) % lenCicle[liderCicle[b]])<<endl;
        }

        // Si a esta en un ciclo y b no, no se puede
        else cout<<-1<<endl;
    }
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