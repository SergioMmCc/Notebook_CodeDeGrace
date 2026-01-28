#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pb push_back

const int MAXN = 2e5 + 6;
typedef pair<int, int> pii;
vector<set<int>> graph;
vector<bool> start, visited;
set<int> to, vertex;
vector<int> maxVisit;

void BFS(int s){
    visited[s] = 1;
    maxVisit[s] = s;
    vector<int> component; component.pb(s);
    int maxV = s;
    queue<int> q; q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(!visited[v]){
                visited[v] = 1;
                component.pb(v);
                q.push(v);
                maxVisit[v] = v;
            }
            maxV = max(maxV, maxVisit[v]);
        }
    }
    
    for(int u : component)
        maxVisit[u] = maxV;
}

void BFS_visit(){
    for(int i : vertex){
        if(!visited[i])
            BFS(i);
    }
}

void clearEverything(int n){
    n += 5;
    graph.clear(); graph.resize(n);
    visited.clear(); visited.resize(n);
    maxVisit.clear(); maxVisit.resize(n);
    start.clear(); start.resize(n);
    to.clear();
    vertex.clear();
}

void solver(){
    int n, m;
    cin>>n>>m;
    int biggest = 0;
    int maxL = 0;
    vector<pii> aux;
    for(int i = 0; i < n; i++){
        int l;cin>>l;
        maxL = max(l, maxL);
        set<int> a;
        for(int j = 0; j < l; j++){
            int save;cin>>save;
            a.insert(save);
        }
        
        int num1, num2 = -1;
        bool min1 = false, min2 = false;
        while(!min2){
            num2++;
            if(a.find(num2) == a.end()){
                if(!min1){
                    min1 = 1;
                    num1 = num2;
                }
                else min2 = 1;
            }
        }
        
        aux.pb({num1, num2});
    }
    
    clearEverything(maxL);
    
    for(auto [num1, num2] : aux){
        graph[num1].insert(num2);
        vertex.insert(num1);
        if(!start[num1])
            start[num1] = 1;
        else
            to.insert(num1);
    }

    BFS_visit();

    for(int i : to)
        biggest = max(biggest, maxVisit[i]);
    set<int>::iterator it = vertex.end(); --it;
    biggest = max(biggest, *it);
    
    int ans = 0;
    for(int i : vertex){
        if(i > m)
            break;
        if(maxVisit[i] > biggest){
            ans += maxVisit[i];
            ans -= max(i, biggest);
        }
    }
    
    if(biggest >= m)
        ans += biggest * (m + 1);
    else
        ans += biggest * (biggest + 1) / 2 + m * (m + 1) / 2;

    cout<<ans<<endl;
}

#undef int
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}