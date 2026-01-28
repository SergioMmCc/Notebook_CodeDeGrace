#include<bits/stdc++.h>
using namespace std;

const long long infinite = 1e18 + 1;

typedef pair<long long, int> pli;
typedef pair<string, long long> psl;
set<psl> orden;
vector<vector<pli>> G(101);
vector<long long> d(101, infinite);
priority_queue<long long, vector<long long>, greater<long long>> pq;
priority_queue<pli, vector<pli>, greater<pli>> imp;

void dijkstra() {
    int u, v;
    long long w;
    d[1] = 0;
    pq.push(1);
    while(!pq.empty()) {
        u = pq.top();
        pq.pop();

        for(pli v : G[u]) {
            if(d[u] + v.first < d[v.second]) {
                d[v.second] = d[u] + v.first;
                pq.push(v.second);
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m;
    int u, v;
    pli save;
    long long games = 0;
    long long w;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    
    string salida = "1";
    for(int i = 1; i < n; i++)
        salida += '0';

    dijkstra();

    if(d[n] == infinite) {
        cout << "inf";
        return 0;
    }
        
    for(int i = 1; i <= n; i++) 
        imp.push({d[i], i});

    while(imp.top().second != n && games < n*n) {
        save = imp.top();
        imp.pop();
        salida[save.second - 1] = '1';
        if(imp.top().first > save.first) {
            orden.insert({salida, imp.top().first - save.first});
            games++;
        }
    }

    cout << d[n] << " " << games << "\n";
    for(psl imprimir : orden)
        cout << imprimir.first << " " << imprimir.second << "\n";

    return 0;
}