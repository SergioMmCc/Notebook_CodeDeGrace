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

int LOG_N = 18; // techo del log2 del maximo valor de k que me puedan dar en las queries
const int maxn = 2e5 + 1;
int n;
vi func(maxn), liderCicle(maxn), stCicle(maxn), lenCicle(maxn), distCicle(maxn), whereCicle(maxn);
vb vis(maxn), isCicle(maxn);
vector<vi> succ(LOG_N, vi(maxn));

// Para cada nodo se calcula a donde llega tras realizar 2^x pasos. Se necesita para usar
// la funcion kSucc.
// Complejidad: O(n * log(k))
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

// x es el nodo inicial desde el cual se va a buscar un ciclo
int floyd(int x){
    vis[x] = 1;
    int a = func[x];
    int b = func[func[x]];

    // En el momento en que a y b se encuentran, a ha caminado k pasos y b 2k pasos, 
    // entonces la longitud del ciclo divide k (k % len == 0)
    while(a != b){
        if(vis[a]) return 0;
        vis[a] = 1;
        a = func[a];
        b = func[func[b]];
    }

    // El primer nodo que pertenece al ciclo (partiendo desde x) se encuentra moviendo 
    // el puntero a al nodo x y avanazando a y b paso por paso hasta que se encuentran 
    // de nuevo
    a = x;
    while(a != b){
        a = func[a];
        b = func[b];
    }

    // En este punto tanto a como b estan parados en el nodo inicial del ciclo, entonces 
    // para hallar la longitud del ciclo simplemente se puede avanzar b paso por paso 
    // hasta que se vuelva a encontrar con a, la cantidad de pasos dados es la longitud 
    // del ciclo
    int length = 1;
    int lider = b;
    liderCicle[lider] = b;
    isCicle[b] = 1;
    lenCicle[b] = 1;
    int last = 0;
    vis[lider] = 1;
    b = func[b];
    while(a != b){
        liderCicle[b] = lider;
        // cout<<"x -> "<<x<<" b -> "<<b<<" lider -> "<<liderCicle[b]<<endl;
        lenCicle[lider]++;
        last++;
        stCicle[b] = last;
        isCicle[b] = 1;
        vis[b] = 1;
        b = func[b];
        length++;
    }

    return length;
}

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

    // for(int i = 1; i <= n; i++){
    //     cout<<"isCicle -> "<<isCicle[i]<<" liderCicle -> "<<liderCicle[i]<<" stCicle -> "<<stCicle[i]<<" distCicle -> "<<distCicle[i]<<" lenCicle -> "<<lenCicle[i]<<" whereCicle -> "<<whereCicle[i]<<endl;
    // }

    while(q--){
        int a, b; cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
            continue;
        }
        if(isCicle[a] && isCicle[b]){
            if(liderCicle[a] != liderCicle[b]) cout<<-1<<endl;
            else cout<<(stCicle[b] - stCicle[a] + lenCicle[liderCicle[a]]) % lenCicle[liderCicle[a]]<<endl;
        }
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
        else if(!isCicle[a] && isCicle[b]){
            // cout<<"here -> "<<a<<' '<<b;
            // cout<<" distCicle -> "<<distCicle[a]<<" stCicle[b] -> "<<stCicle[b]<<" stCicleWA -> "<<stCicle[whereCicle[a]]<<" len -> "<<lenCicle[liderCicle[b]]<<" op -> "<<(stCicle[b] - stCicle[whereCicle[a]] + lenCicle[liderCicle[b]]) % lenCicle[liderCicle[b]]<<endl;
            if(liderCicle[whereCicle[a]] != liderCicle[b]) cout<<-1<<endl;
            else cout<<distCicle[a] + ((stCicle[b] - stCicle[whereCicle[a]] + lenCicle[liderCicle[b]]) % lenCicle[liderCicle[b]])<<endl;
        }
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