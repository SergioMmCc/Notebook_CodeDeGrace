#include "../template.h"

/*
- Complejidad: O(v²*sqrt(e)) o (v³)
- Si las constantes son bajas, usar Dinic (mas corto).
- Para bipartitos con capacidad 1, usar Dinic (mas eficiente).
- Si se requiere hallar el flujo que se envia por cada arista o cuales 
  nodos estan en cada lado del corte, usar Dinic.
*/

struct HLPP {
    typedef ll F; // flow type
    struct Edge { int to, rev; F f; };
    const F INF = numeric_limits<F>::max();

    int N, s, t;
    vector<vector<Edge>> adj;
    vector<vi> lst, gap;
    vector<F> excess;
    vi height, cnt;
    int highest, work;

    HLPP(int n) : N(n), s(0), t(0), adj(n), lst(n), gap(n),
                  excess(n), height(n), cnt(n), highest(0), work(0) {}

    void ae(int u, int v, F cap){
        assert(cap >= 0);
        Edge a{v, sz(adj[v]), cap}, b{u, sz(adj[u]), 0};
        adj[u].pb(a), adj[v].pb(b);
    }
    void updHeight(int v, int nh){
        work++;
        if(height[v] != N) cnt[height[v]]--;
        height[v] = nh;
        if(nh == N) return;
        cnt[nh]++, highest = nh;
        gap[nh].pb(v);
        if(excess[v] > 0) lst[nh].pb(v);
    }
    void globalRelabel(){
        work = 0;
        for0(i,N) height[i] = N, cnt[i] = 0;
        for0(i,highest) lst[i].clear(), gap[i].clear();
        height[t] = 0;
        queue<int> q({t});
        while(sz(q)){
            int v = q.front(); q.pop();
            for(auto &e : adj[v]){
                if(e.to != s && height[e.to] == N && adj[e.to][e.rev].f > 0){
                    q.push(e.to), updHeight(e.to, height[v] + 1);
                }
            }
            highest = height[v];
        }
    }
    void push(int v, Edge& e){
        if(excess[e.to] == 0 && height[e.to] < N) lst[height[e.to]].pb(e.to);
        F df = min(excess[v], e.f);
        e.f -= df, adj[e.to][e.rev].f += df;
        excess[v] -= df, excess[e.to] += df;
    }
    void discharge(int v){
        if(height[v] >= N) return;
        int nh = N;
        for(auto &e : adj[v]){
            if(e.f > 0){
                if(height[v] == height[e.to] + 1){
                    push(v, e);
                    if(excess[v] <= 0) return;
                } else nh = min(nh, height[e.to]+1);
            }
        }
        if(cnt[height[v]] > 1) updHeight(v, nh);
        else{
            forlr(i,height[v],highest) {
                for(auto &j : gap[i]) updHeight(j, N);
                gap[i].clear();
            }
        }
    }
    F maxFlow(int _s, int _t){
        s = _s, t = _t; if(s == t) return -1;
        for0(i,N) excess[i] = 0;
        excess[s] = INF, excess[t] = -INF;
        globalRelabel();
        for(auto &e : adj[s]) push(s,e);
        for(; highest >= 0; highest--){
            while(sz(lst[highest])){
                int v = lst[highest].back();
                lst[highest].pop_back();
                discharge(v);
                if(work > 4*N) globalRelabel();
            }
        }
        return excess[t] + INF;
    }
};

void solver(){
    int n, m; cin>>n>>m;
	HLPP graph(n+1); // Crear el grafo
    for0(i,m){
        int u, v; ll c; cin>>u>>v>>c;
        graph.ae(u, v, c); // Agregar arista dirigida u -> v con capacidad c
    }

    ll flow = graph.maxFlow(s, t); // Si s == t, retorna -1
    cout<<flow<<endl;
}