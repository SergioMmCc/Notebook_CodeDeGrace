#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 2e5 + 5;
set<int> graph[maxn];

vector<int> leader(maxn);
vector<int> sets[maxn];
int components;

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sets[i].push_back(i);
    }
}

void join(int u, int v){
    int leaderU = leader[u], leaderV = leader[v];
    if(leaderU != leaderV){
        if(sets[leaderV].size() > sets[leaderU].size())
            swap(leaderU, leaderV);
        
        for(int i = 0; i < sets[leaderV].size(); i++){
            int v = sets[leaderV][i];
            leader[v] = leaderU;
            sets[leaderU].push_back(v);
        }
        sets[leaderV].clear();
        components--;
    }
}

vector<bool> analized(maxn + 1);

void DFS(int s, int n){
    for(int i = 1; i <= n; i++){
        if(analized[i]) continue;
        if(graph[s].find(i) == graph[s].end()){
            analized[i] = 1;
            join(i, s);
            DFS(i, n);
        }
    }
}

void solver(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    initDSU(n);

    // Brute force si n <= 10000
    if(n <= 10000){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                while(!graph[i].empty() && *graph[i].begin() < j) graph[i].erase(*graph[i].begin());
                if(!graph[i].empty() && *graph[i].begin() == j) continue;
                join(i, j);
            }
        }

        cout<<components<<endl;
        multiset<int> ans;
        for(int i = 1; i <= n; i++){
            if(leader[i] == i) ans.insert(sets[i].sz);
        }
        for(int i : ans) cout<<i<<' ';
        cout<<endl;
        return;
    }

    // Respuesta si n > 10000
    // Max de 40 aristar por vertice
    int testLimit = (2 * m) / n; // Si se dividieran las aristas en partes iguales, cuantas tendria cada uno
    for(int i = 1; i <= n; i++){
        if(!analized[i] && graph[i].sz <= testLimit){
            analized[i] = 1;
            set<int>::iterator it = graph[i].begin();
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(it == graph[i].end() || j < *it){join(i, j); analized[j] = 1;}
                if(it != graph[i].end() && j == *it) ++it;
            }
            
            stack<int> st;
            for(int u : sets[i]){
                if(u == i) continue;
                st.push(u);
            }
            while(!st.empty()){
                int u = st.top(); st.pop();
                for(int v : graph[i]){
                    if(analized[v]) continue;
                    if(graph[u].find(v) == graph[u].end()){
                        join(i, v);
                        st.push(v);
                        analized[v] = 1;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(analized[i]) continue;
        analized[i] = 1;
        DFS(i, n);
    }

    cout<<components<<endl;
    multiset<int> ans;
    for(int i = 1; i <= n; i++){
        if(leader[i] == i) ans.insert(sets[i].sz);
    }
    for(int i : ans) cout<<i<<' ';
    cout<<endl;
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