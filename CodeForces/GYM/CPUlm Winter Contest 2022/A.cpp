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

const int maxn = 1e5 + 1;
vector<vector<int>> graph(maxn);
vector<int> degree(maxn);

bool check(int s, int n){
    vector<bool> visited(n+1); visited[s] = 1;
 
    queue<pii> q;
    if(s == 1) q.push({2, -1});
    else q.push({1, -1});
    visited[q.front().fi] = 1;
    int count = 2;
 
    while(!q.empty()){
        int u = q.front().fi, p = q.front().se; q.pop();
 
        for(int v : graph[u]){
            if(v == p || v == s) continue;
            if(visited[v]) return 0;
            count++;
            visited[v] = 1;
            q.push({v, u});
        }
    }
 
    if(count != n) return 0;
 
    int count1 = 0;
    for(int i = 1; i <= n; i++){
        if(i == s) continue;
        int aux = 0;
        for(int v : graph[i]){
            if(v == s) continue;
            aux++;
        }
 
        if(aux > 2) return 0;
        if(aux == 1) count1++;
    }
 
    return count1 == 2 ? 1 : 0;
}

void solver(){
    int n, m; cin>>n>>m;

    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        degree[u]++; degree[v]++;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<vector<int>> vDeg(5);
    for(int i = 1; i <= n; i++){
        if(degree[i] > 3) vDeg[4].pb(i);
        else vDeg[degree[i]].pb(i);
    }

    if(vDeg[4].sz > 1){
        cout<<"no"<<endl;
        return;
    }

    if(vDeg[4].sz == 1){
        bool cond = check(vDeg[4][0], n);
        cout<<(cond ? "yes" : "no")<<endl;
        return;
    }

    if(vDeg[3].sz > 4){
        cout<<"no"<<endl;
        return;
    }

    if(vDeg[3].sz > 1){
        bool cond = 0;
        for(int i = 0; !cond && i < vDeg[3].sz; i++){
            cond = check(vDeg[3][i], n);

            for(int k = 0; !cond && k < graph[vDeg[3][i]].sz; k++)
                cond = check(graph[vDeg[3][i]][k], n);
        }
            
        cout<<(cond ? "yes" : "no")<<endl;
        return;
    }

    if(vDeg[3].sz == 1){
        int s = vDeg[3][0];
        bool cond = 0;
        for(int i = 0; !cond && i < graph[s].sz; i++)
            cond = check(graph[s][i], n);

        cout<<(cond ? "yes" : "no")<<endl;
        return;
    }

    if(vDeg[0].sz > 1){
        cout<<"no"<<endl;
        return;
    }

    if(vDeg[0].sz == 1){
        bool cond = check(vDeg[0][0], n);
        cout<<(cond ? "yes" : "no")<<endl;
        return;
    }

    if(vDeg[1].sz > 2){
        cout<<"no"<<endl;
        return;
    }

    if(vDeg[1].sz > 0){
        bool cond = check(vDeg[1][0], n);
        cout<<(cond ? "yes" : "no")<<endl;
        return;
    }

    if(vDeg[2].sz > 0){
        bool cond = check(vDeg[2][0], n);
        cout<<(cond ? "yes" : "no")<<endl;
        return;
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