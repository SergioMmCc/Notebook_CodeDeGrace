#include "../template.h"

/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis:mincostmaxflow, stress-tested against another implementation
 * Time: O(F*E*log(V)) where F is max flow. O(V*E) for setpi.
 * 0-index.
*/

#include <ext/pb_ds/priority_queue.hpp>

struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vi seen;
	vl dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost){
		if(from == to) return;
		ed[from].pb(edge{from,to, sz(ed[to]), cap, cost, 0});
		ed[to].pb(edge{to, from, sz(ed[from])-1, 0, -cost, 0});
	}

	void path(int s){
		fill(all(seen), 0);
		fill(all(dist), INFL);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		while(!q.empty()){
			s = q.top().se; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for(edge& e : ed[s]) if(!seen[e.to]){
				ll val = di - pi[e.to] + e.cost;
				if(e.cap - e.flow > 0 && val < dist[e.to]){
					dist[e.to] = val;
					par[e.to] = &e;
					if(its[e.to] == q.end())
						its[e.to] = q.push({-dist[e.to], e.to});
					else
						q.modify(its[e.to], {-dist[e.to], e.to});
				}
			}
		}
		for0(i,N) pi[i] = min(pi[i] + dist[i], INFL);
	}

	pll maxflow(int s, int t){
		ll totflow = 0, totcost = 0;
		while(path(s), seen[t]){
			ll fl = INFL;
			for(edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for(edge* x = par[t]; x; x = par[x->from]){
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		for0(i,N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s){ // (otherwise, leave this out)
		fill(all(pi), INFL); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while(ch-- && it--)
			for0(i,N) if(pi[i] != INFL)
			    for(edge& e : ed[i]) if(e.cap)
				    if((v = pi[i] + e.cost) < pi[e.to])
					    pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

void solver(){
    int n, m; cin>>n>>m;
    MCMF graph(n + 1); // Inicializa la red

	// Agregar aristas u -> v, con capacidad cap y costo cost por cada unidad de flujo
    for0(i,m){
        int u, v; ll cap, cost; cin>>u>>v>>cap>>cost;
        graph.addEdge(u, v, cap, cost);
    }

    cout<<graph.maxflow(s, t).se<<endl;
}