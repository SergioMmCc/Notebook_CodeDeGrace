#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 150005;
vector<vector<int>> tree(maxn);
vector<bool> act(maxn, 1);

piii diameter(int s, vector<int>& parent){

    // Hallar uno de los nodos del diametro
    queue<piii> q; q.push({s, {-1, 0}});
    pii maxi = {0, s};
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se.fi, d = q.front().se.se; q.pop();
        for(int v : tree[u]){
            if(!act[v] || pa == v) continue;
            maxi = max(maxi, {d + 1, v});
            q.push({v, {u, d + 1}});
        }
    }

    // Hallar el otro nodo del diametro y su distancia
    int l = maxi.se;
    parent[l] = -1;
    q.push({l, {-1, 0}});
    maxi = {0, l};
    while(!q.empty()){
        int u = q.front().fi, pa = q.front().se.fi, d = q.front().se.se; q.pop();
        for(int v : tree[u]){
            if(!act[v] || pa == v) continue;
            parent[v] = u;
            maxi = max(maxi, {d + 1, v});
            q.push({v, {u, d + 1}});
        }
    }

    int r = maxi.se, dis = maxi.fi + 1;
    
    // Reconstruir el camino para desactivar los nodos y crear los siguientes subtrees
    int u = r, last = -1;
    while(u != -1){
        act[u] = 0;

        last = u;
        u = parent[u];
    }

    if(r > l) swap(l, r);
    return {dis, {l, r}};
}

void solver(){
    int n; cin>>n;

    // Limpiar las variables globales
    for(int i = 1; i <= n; i++){
        tree[i].clear();
        act[i] = 1;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vector<int> parent(n+1);
    priority_queue<piii> ans;
    for(int i = 1; i <= n; i++){
        while(act[i]){
            ans.push(diameter(i, parent));
        }
    }

    while(!ans.empty()){
        piii a = ans.top(); ans.pop();
        cout<<a.fi<<' '<<a.se.fi<<' '<<a.se.se<<' ';
    }
    cout<<endl;
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