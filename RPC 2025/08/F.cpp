#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;

int dist(int u, vector<int>& graph, vector<int>& dis, vector<int>& len){
    if(dis[u] == -1){
        dis[u] = dist(graph[u], graph, dis, len) + 1;
        len[u] = len[graph[u]];
    }
    return dis[u];
}

void solver(){
    int n, c; cin>>n>>c;
    vector<int> a(n+1), ps(2*n + 1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ps[i] = ps[i-1] + a[i];
    }

    for(int i = n+1; i <= 2*n; i++) ps[i] = ps[i-1] + a[i - n];

    // for(int i = 1; i <= 2*n; i++) cout<<ps[i]<<' ';
    vector<int> graph(n+1);
    for(int i = 1; i <= n; i++){
        auto it = lower_bound(ps.begin(), ps.end(), ps[i-1] + c);
        if(it == ps.end()) graph[i] = i;
        else{
            int index = it - ps.begin() + 1;
            if(index > n) index -= n;
            graph[i] = index;
        }
    }

    // for(int i = 1; i <= n; i++) cout<<"i -> "<<i<<" j -> "<<graph[i]<<endl;

    // Ahora hallar si cada vertice pertenece a un ciclo y cual es el tamaño de este
    vector<bool> visited(n+1);
    vector<int> dis(n+1, -1), len(n+1, -1), disc(n+1);
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        int count = 0;

        int u = i;
        while(!visited[graph[u]]){
            count++;
            u = graph[u];
            visited[u] = 1;
            disc[u] = count;
        }
        u = graph[u];
        count -= disc[u];

        while(len[u] == -1){
            len[u] = count;
            u = graph[u];
            dis[u] = 0;
        }
    }

    // for(int i = 1; i <= n; i++) cout<<len[i]<<' '; cout<<endl;

    // Ahora hallar la distancia de cada nodo a un ciclo
    for(int i = 1; i <= n; i++) dist(i, graph, dis, len);
    for(int i = 1; i <= n; i++){
        cout<<dis[i] + len[i];
        // cout<<" dis -> "<<dis[i]<<" len -> "<<len[i]<<endl;
        if(i < n) cout<<' ';
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}