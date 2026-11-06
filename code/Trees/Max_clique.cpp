#include "../template.h"

/*
- Usar grafo 0-index.
- Halla el maximum clique en un grafo no dirigido.
- Con 50 nodos corre en menos de 1 segundo.
*/

const int N = 50;

typedef vector<bitset<N>> graph;
struct Maxclique {
    double limit = 0.025, pk = 0;
    struct Vertex {
        int i, d = 0;
    };
    typedef vector<Vertex> vv;
    graph e;
    vv V;
    vector<vi> C;
    vi qmax, q, S, old;
    void init(vv& r){
        for(auto& v : r) v.d = 0;
        for(auto& v : r) for(auto j : r) v.d += e[v.i][j.i];
        sort(all(r), [](auto a, auto b) {
            return a.d > b.d;
            });
        int mxD = r[0].d;
        for0(i,sz(r)) r[i].d = min(i, mxD) + 1;
    }
    void expand(vv& R, int lev = 1){
        S[lev] += S[lev - 1] - old[lev];
        old[lev] = S[lev - 1];
        while(sz(R)){
            if(sz(q) + R.back().d <= sz(qmax)) return;
            q.pb(R.back().i);
            vv T;
            for(auto v : R) if(e[R.back().i][v.i]) T.pb({ v.i });
            if(sz(T)) {
                if(S[lev]++ / ++pk < limit) init(T);
                int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);
                C[1].clear(), C[2].clear();
                for(auto v : T){
                    int k = 1;
                    auto f = [&](int i){
                        return e[v.i][i];
                        };
                    while(any_of(all(C[k]), f)) k++;
                    if(k > mxk) mxk = k, C[mxk + 1].clear();
                    if(k < mnk) T[j++].i = v.i;
                    C[k].pb(v.i);
                }
                if(j > 0) T[j - 1].d = 0;
                forlr(k,mnk,mxk) for(int i : C[k])
                    T[j].i = i, T[j++].d = k;
                expand(T, lev + 1);
            }
            else if(sz(q) > sz(qmax)) qmax = q;
            q.pop_back(), R.pop_back();
        }
    }
    Maxclique(graph g) : e(g), C(sz(e) + 1), S(sz(C)), old(S) {
        for0(i,sz(e)) V.pb({i});
    }
    vector<int> solve(){ // returns the clique
        init(V), expand(V);
        return qmax;
    }
};

void solver(){
    // Construir el grafo
    int n; cin>>n;
    graph g(n);
    for0(i,n){
        for0(j,n){
            int num; cin>>num;
            g[i][j] = (num ? 1 : 0); // Lectura como matriz de adyacencia
        }
    }

    // Correr el algoritmo
    Maxclique mc(g);
    vi clique = mc.solve();
    cout<<sz(clique)<<endl; // Tamaño del max clique

    // Vertices en el max clique
    for(int v : clique) cout<<v<<' ';
    cout<<endl;
}