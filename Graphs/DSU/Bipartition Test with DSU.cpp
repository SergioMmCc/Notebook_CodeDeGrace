#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 200005;
int components;
vector<int> leader(maxn), sizen(maxn), len(maxn);
// En el array len almacenamos la paridad de la distancia de
// un vertice v a su lider

// Este algortimo sirve para ir agregando aristas a un grafo
// de modo que siga siendo bipartito, hasta que llegue un punto
// en el que sea imposible que el grafo siga siendo bipartito
// Source: https://codeforces.com/edu/course/2/lesson/7/2

// Implementar DSU modificado para llenar el vector "len"
void initDSU(int n){
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
        len[i] = 0;
    }
}

pii find(int u){
    if(leader[u] == u) return {u, 0};
    
    pii val = find(leader[u]);
    leader[u] = val.first;
    len[u] = (len[u] + val.second) % 2;
    return {leader[u], len[u]};
    // Retorna el lider de u y la paridad de la distancia al lider
}

void join(int u, int v){
    pii valU = find(u), valV = find(v);
    if(valU.first != valV.first){
        if(sizen[valU.first] > sizen[valV.first])
            swap(valU, valV);
        leader[valU.first] = valV.first;
        len[valU.first] = (1 + valU.second + valV.second) % 2;
        // La distancia entre el lider de u y el lider de v es igual
        // a la distancia entre u y su lider, mas la distancia entre
        // v y su lider, y una arista entre u y v
        sizen[valV.first] += sizen[valU.first];
    }
}

void updateAllLeaders(int n){
    for(int i = 1; i <= n; i++)
        find(i);
}

void solver(){
    int n, m; cin>>n>>m;
    initDSU(n);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        join(u, v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}