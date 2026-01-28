#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 100000

long long const inf = 2e9;

typedef pair<int, int> pii;
vector<pii> graph[MAXN+1];

struct comp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void dijkstra(int source, vector<int>& distance){
    distance[source] = 0;
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push({source, 0});
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        for(pii v : graph[u]){
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
            cin>>u>>v;
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 1});
        }
        
        vector<int> distanceB(j+1, inf), distanceC(j+1, inf), distanceN(j+1, inf);
        dijkstra(b, distanceB);
        dijkstra(c, distanceC);
        dijkstra(n, distanceN);

        int maxTogether = 0, charlyAlone = distanceB[c], nitoAlone = distanceB[n];
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