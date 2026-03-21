#include <bits/stdc++.h>
using namespace std;
#define MAXT 10002
#define inf 2100000000 

vector<int> pesos(MAXT);
typedef vector<vector<pair<int, int>>> g;
g graph(MAXT, vector<pair<int, int>>());
int result = 2100000000;

void dijkstra(const g &aux, int vertex) {
    int u, v, w;
    vector<int>d(MAXT, inf);
    d[vertex] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < vertex+2; i++) 
        pq.push({d[i], i});
    
    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < aux[u].size(); i++) {
            v = aux[u][i].first;
            w = aux[u][i].second; 
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    if (d[vertex+1] < result)
        result = d[vertex+1];
}

void query(int vertex) {
    g aux(MAXT, vector<pair<int, int>>());
    int start = 0, end = 0, mid = vertex / 2;
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < graph[i].size(); j++)
            aux[i].push_back({graph[i][j].first, graph[i][j].second});
    }
    int k;
    for (k = 0; k < vertex && start < mid && end < mid; k++) {
        if(rand() % 2 == 1) {
            start++;
            aux[vertex].push_back({k, pesos[k]});
            aux[k].push_back({vertex, pesos[k]});
        }
        else {
            end++;
            aux[vertex+1].push_back({k, pesos[k]});
            aux[k].push_back({vertex+1, pesos[k]});
        }
    }
    if(start < mid) {
        while(k < vertex) {
            aux[vertex].push_back({k, pesos[k]});
            aux[k].push_back({vertex, pesos[k]});
            k++;
        }
    }
    else if(end < mid) {
        while(k < vertex) {
            aux[vertex+1].push_back({k, pesos[k]});
            aux[k].push_back({vertex+1, pesos[k]});
            k++;
        }
    }
    dijkstra(aux, vertex);
}

int main() {
    int vertex, edge; cin >> vertex >> edge;
    int v, u, w;
    for (int i = 0; i < vertex; i++) 
        cin >> pesos[i];
    
    if (vertex == 1) {
        cout << pesos[0] << endl;
        return 0;
    }
    for (int i = 0; i < edge; i++) {
        cin >> v >> u >> w;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }
    for(int i = 0; i < 50; i++)
        query(vertex);
    
    cout << result << endl;
 
    return 0;
}