#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100000

long long const inf = 1e18;

typedef pair<int, long long> pil;
vector<pil> graph[MAXN+1];

struct comp{
    bool operator() (pil a, pil b){
        return a.second > b.second;
    }
};

void dijkstra(int source, vector<long long>& distance){
    distance[source] = 0;
    priority_queue<pil, vector<pil>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        for(pil v : graph[u]){
            if(distance[v.first] > distance[u] + v.second){
                distance[v.first] = distance[u] + v.second;
                pq.push({v.first, distance[v.first]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int j, b, c, n, s;
    while(cin>>j>>b>>c>>n>>s && j != -1){
        
        for(int i = 1; i <= j; i++)
            graph[i].clear();
        for(int i = 0; i < s; i++){
            int u, v;
            long long w;
            cin>>u>>v>>w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        vector<long long> distanceB(j+1, inf), distanceC(j+1, inf), distanceN(j+1, inf);
        dijkstra(b, distanceB);
        dijkstra(c, distanceC);
        dijkstra(n, distanceN);

        long long maxTogether = 0, charlyAlone = distanceB[c], nitoAlone = distanceB[n];
        for(int i = 1; i <= j; i++){
            if(distanceB[i] + distanceC[i] == distanceB[c]
            && distanceB[i] + distanceN[i] == distanceB[n]){
                if(distanceB[i] > maxTogether){
                    maxTogether = distanceB[i];
                    charlyAlone = distanceC[i];
                    nitoAlone = distanceN[i];
                }
            }
        }
        cout<<maxTogether<<' '<<charlyAlone<<' '<<nitoAlone<<endl;
    }

    return 0;
}