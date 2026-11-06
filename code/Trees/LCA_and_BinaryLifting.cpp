#include "../template.h"

// Todo es 1-index

int LOG_N = 18; // techo del log2 de n

// Para cada nodo se calcula a donde llega tras realizar 2^x pasos. 
// Se necesita para hallar el LCA y para la funcion kStep.
// Complejidad: O(n * log(k))
void calc(int n, vi& pa, vector<vi>& up){
    for1(i,n) up[0][i] = pa[i];
    for1(bit,LOG_N-1){
        for1(i,n){
            up[bit][i] = up[bit-1][up[bit-1][i]];
        }
    }
}

int LCA(int a, int b, vi& depth, vector<vi>& up){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    // Este ciclo pone a y b en el mismo nivel
    forn0(j,LOG_N) if(k & (1 << j)) a = up[j][a];

    if(a == b) return a;

    forn0(j,LOG_N){
        if(up[j][a] != up[j][b]){
            a = up[j][a];
            b = up[j][b];
        }
    }
    return up[0][a];
}

// Retorna el nodo al que se llega tras hacer k pasos partiendo desde s
// Complejidad: O(log(k))
int kStep(int s, int k, vector<vi>& up, vi& depth){
    if(depth[s] < k) return -1; // Si s tiene menos profundidad que la cantidad de pasos que me piden
    for0(bit,LOG_N){
        if(k & (1 << bit)) s = up[bit][s];
    }

    return s;
}

void solver(){
    int n; cin>>n;
    // Precalcular depth y pa con DFS
    vi depth(n+1), pa(n+1);
    
    // Precalcular la matriz up
    vector<vi> up(LOG_N, vi(n+1));
    calc(n, pa, up);

    // Preguntar LCA
    cout<<LCA(u, v, depth, up)<<endl;

    // Preguntar kth step
    cout<<kStep(node, steps, up, depth)<<endl;;
}