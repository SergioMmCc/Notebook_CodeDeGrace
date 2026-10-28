#include "../template.h"

/*
- Se usa en grafos funcionales para contestar a que nodo se llega 
  tras realizar k pasos iniciando en el nodo s.
- Complejidad: Precalculo: O(n * log(k)), queries en O(log(k)).
*/

const int maxn = 1e5 + 1;
const int LOG_N = 30; // techo del log2 del maximo valor de k que me puedan dar en las queries
vector<vi> succ(LOG_N, vi(maxn));

void calcSucc(int n, vi& func){
    for1(i,n) succ[0][i] = func[i];
    for1(bit,LOG_N-1) for1(i,n) succ[bit][i] = succ[bit-1][succ[bit-1][i]];
}

int kSucc(int s, int k){
    for0(bit,LOG_N) if(k & (1 << bit)) s = succ[bit][s];
    return s;
}

void solver(){
    int n, q; cin>>n>>q;
    vi func(n+1);
    for1(i,n) cin>>func[i];
    calcSucc(n, func); // Precalcular primero
    while(q--){
        int s, k; cin>>s>>k;
        cout<<kSucc(s, k)<<endl;
    }
}