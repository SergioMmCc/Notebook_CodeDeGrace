#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 5001;
const int inf = 1e9;
vector<vector<pii>> graph(maxn);

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

// Complejidad O(m*log(n))
void dijkstra(int source, int n, vector<int>& d){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[source] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first, w1 = pq.top().second;
        pq.pop();
        if(d[u] < w1) continue;
        for(pii edge : graph[u]){
            int v = edge.first, w2 = edge.second;
            if(d[v] > w1 + w2){
                d[v] = w1 + w2;
                pq.push({v, d[v]});
            }
        }
    }
}

int main(){
	int n, m; cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v, w; char l; cin>>u>>v>>l>>w;
		if(l == 'r') w*= -1;
		graph[u].pb({v, w});
	}

    vector<int> d(n+1);
    dijkstra(1, n, d);

    for(int i = 2; i <= n; i++){
        if(d[i] < 0) cout<<i<<endl;
    }
}