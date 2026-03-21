#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 1001
using ll = long long;

typedef pair<int, int> pii;
vector<pii> ranges;
vector<bool> bitMask (MAXN, false);
int lengthMis;
set<int> matriz[MAXN];

struct comp{
    bool operator() (pii a, pii b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, adj[b].size(), c, c});
		adj[b].push_back({a, adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for(ll L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int> (q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void createMis(int test){
    vector<int> mis;
    int lastEnd = -1, count = 0;
    bool cond = false;
    for(int i = 0; i < ranges.size(); i++){
        if(i == test)
            cond = true;
        if(!cond && ranges[i].second >= ranges[test].first)
            continue;
        if(ranges[i].first > lastEnd){
            mis.push_back(i);
            count++;
            lastEnd = ranges[i].second;
        }
    }
    if(count == lengthMis){
        int index = 1;
        for(int i : mis){
            bitMask[i] = true;
            matriz[index].insert(i);
            index++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n; cin>>n;
    Dinic graph(2*n + 2);
    for(int i = 0; i < n; i++){
        graph.addEdge(2*i, 2*i + 1, 1);
        int l, r;
        cin>>l>>r;
        ranges.push_back({l, r});
    }
    
    sort(ranges.begin(), ranges.end(), comp());
    
    int lastEnd = -1;
    for(int i = 0; i < n; i++){
        if(ranges[i].first > lastEnd){
            lengthMis++;
            matriz[lengthMis].insert(i);
            bitMask[i] = true;
            lastEnd = ranges[i].second;
        }
    }
    for(int i = 0; i < n; i++){
        if(bitMask[i])
            continue;
        createMis(i);
    }
    for(int i = 1; i < lengthMis; i++){
        int count = 0;
        for(set<int>::iterator j = matriz[i].begin(); j != matriz[i].end(); ++j){
            int u = *j;
            for(set<int>::iterator k = matriz[i+1].begin(); k != matriz[i+1].end(); ++k){
                int v = *k;
                if(ranges[u].second < ranges[v].first)
                    graph.addEdge(2*u + 1, 2*v, 1);
            }
        }
    }
    for(int i : matriz[1])
        graph.addEdge(2*n, 2*i, 1);
    for(int i : matriz[lengthMis])
        graph.addEdge(2*i + 1, 2*n + 1, 1);
    
    cout<<graph.calc(2*n, 2*n + 1)<<endl;
 
    return 0;
}