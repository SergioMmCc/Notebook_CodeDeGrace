#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, ld> pid;

const int maxn = 501;
const ld ninf = -1000000000.0;
vector<pid> graph[maxn];

struct comp{
    bool operator() (pid a, pid b){
        return a.second < b.second;
    }
};

// Complejidad O(m*log(n))
void dijkstra(int source, int n, vector<ld>& d){
    for(int i = 1; i <= n; i++) d[i] = ninf;
    d[source] = 0.0;
    priority_queue<pid, vector<pid>, comp> pq;
    pq.push({source, 0.0});
    while(!pq.empty()){
        int u = pq.top().first; ld w1 = pq.top().second;
        pq.pop();
        if(d[u] > w1) continue;
        for(pid edge : graph[u]){
            int v = edge.first; ld w2 = edge.second;
            if(d[v] < w1 + w2){
                d[v] = w1 + w2;
                pq.push({v, d[v]});
            }
        }
    }
}

void solver(int n, int m){
    for(int i = 1; i <= n; i++) graph[i].clear();
    for(int i = 0; i < m; i++){
        int u, v; ld w;
        cin>>u>>v>>w;
        if(w == 0.0) continue;
        w = log10(w);
        graph[u].push_back({v, w});
    }

    vector<ld> d(n+1);
    dijkstra(1, n, d);

    if(d[n] == ninf){
        cout<<"Impossible"<<endl;
        return;
    }

    cout<<"10^"<<fixed<<setprecision(4)<<d[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m;
    while(cin>>n>>m){
        solver(n, m);
    }

    return 0;
}