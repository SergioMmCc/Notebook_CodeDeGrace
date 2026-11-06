#include "../template.h"

/*
- Complejidad: O(|E||V|^2)
- Maximum matching en cualquier grafo no dirigido
- Minimum edge cover:
- Es el minimo conjunto de aristas tal que cada nodo del grafo tiene al 
  menos una de sus aristas en dicho conjunto. Esta compuesto por las 
  aristas del matching + para todo vertice no cubierto aun, tomar 
  cualquier arista de este.
*/

const int MAXE = ; // MAXE = 2*n*n
struct network {
    struct struct_edge { int v; struct_edge * n; };
    typedef struct_edge* edge;
    int n;
    struct_edge pool[MAXE];
    edge top;
    vector<edge> adj;
    queue<int> q;
    vi f, base, inq, inb, inp, match;
    vector<vi> ed;
    network(int n) : n(n), match(n, -1), adj(n), top(pool), f(n), base(n),
                     inq(n), inb(n), inp(n), ed(n, vi(n)) {}
    void add_edge(int u, int v){
        if(ed[u][v]) return;
        ed[u][v] = 1;
        top->v = v, top->n = adj[u], adj[u] = top++;
        top->v = u, top->n = adj[v], adj[v] = top++;
    }
    int get_lca(int root, int u, int v){
        fill(inp.begin(), inp.end(), 0);
        while(1){
            inp[u = base[u]] = 1;
            if(u == root) break;
            u = f[match[u]];
        }
        while(1){
            if(inp[v = base[v]]) return v;
            else v = f[match[v]];
        }
    }
    void mark(int lca, int u){
        while(base[u] != lca){
            int v = match[u];
            inb[base[u]] = 1;
            inb[base[v]] = 1;
            u = f[v];
            if(base[u] != lca) f[u] = v;
        }
    }
    void blossom_contraction(int s, int u, int v){
        int lca = get_lca(s, u, v);
        fill(all(inb), 0);
        mark(lca, u); mark(lca, v);
        if(base[u] != lca) f[u] = v;
        if(base[v] != lca) f[v] = u;
        for0(u,n){
            if(inb[base[u]]){
                base[u] = lca;
                if(!inq[u]){
                    inq[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    int bfs(int s){
        fill(all(inq), 0);
        fill(all(f), -1);
        for(int i = 0; i < n; i++) base[i] = i;
        q = queue<int>();
        q.push(s);
        inq[s] = 1;
        while(sz(q)){
            int u = q.front(); q.pop();
            for(edge e = adj[u]; e; e = e->n){
                int v = e->v;
                if(base[u] != base[v] && match[u] != v){
                    if((v == s) || (match[v] != -1 && f[match[v]] != -1))
                        blossom_contraction(s, u, v);
                    else if(f[v] == -1){
                        f[v] = u;
                        if(match[v] == -1) return v;
                        else if(!inq[match[v]]){
                            inq[match[v]] = 1;
                            q.push(match[v]);
                        }
                    }
                }
            }
        }
        return -1;
    }
    int doit(int u){
        if(u == -1) return 0;
        int v = f[u];
        doit(match[v]);
        match[v] = u; match[u] = v;
        return u != -1;
    }
    /// (i < net.match[i]) => means match
    int maximum_matching(){
        int ans = 0;
        for0(u,n)
        ans += (match[u] == -1) && doit(bfs(u));
        return ans;
    }
};

void solver(){
    int n, m; cin>>n>>m;

    // Inicializar
    network graph(n+1);
    for0(i,m){
        int u, v; cin>>u>>v;
        graph.add_edge(u, v);
    }

    int len = graph.maximum_matching(); // Hallar el matching 
    cout<<len<<endl; // Tamaño del matching maximo
    for1(i,n){ // Aristas en el matching
        // La segunda condicion asegura que cada arista se escriba solo una vez
        if(graph.match[i] != -1 && i < graph.match[i]){
            cout<<i<<' '<<graph.match[i]<<endl;
        }
    }
}