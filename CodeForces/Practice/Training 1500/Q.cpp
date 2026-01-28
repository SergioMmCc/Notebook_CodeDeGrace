#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void BFS(vector<int> tree[], int n, vector<int>& sons){
    vector<bool> visited(n+1);
    visited[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(visited[v]) continue;
            sons[u]++;
            visited[v] = 1;
            q.push(v);
        }
    }
}

int DFS(int m, int u, vector<int>& auxSons, vector<int> tree[], int *components, vector<bool>& visited){
    for(int v : tree[u]){
        if(visited[v]) continue;
        visited[v] = 1;
        auxSons[u] += DFS(m, v, auxSons, tree, components, visited);
    }

    if(auxSons[u] >= m - 1){
        (*components)++;
        return -1;
    }
    return auxSons[u];
}

bool check(int n, int k, int m, vector<int>& sons, vector<int> tree[]){
    vector<int> auxSons = sons;
    vector<bool> visited(n+1);
    visited[1] = 1;
    int components = 0;
    DFS(m, 1, auxSons, tree, &components, visited);

    if(components > k) return 1;
    else return 0;
}

void solver(){
    // Leer datos
    int n, k; cin>>n>>k;
    vector<int> tree[n+1];
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    // Buscar cuantos hijos tiene cada vertice, teniendo 1 como raiz
    vector<int> sons(n+1);
    BFS(tree, n, sons);

    // Binary Search para buscar x optimo
    int l = 1, r = n;
    while(l < r){
        int m = (l + r + 1) >> 1;
        bool cond = check(n, k, m, sons, tree);
        if(cond) l = m;
        else r = m - 1;
    }

    cout<<l<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}