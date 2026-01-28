#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void BFS(vector<int>& a, vector<int> graph[], set<int> used[], int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(a[v] != -1) continue;
            used[v].insert(a[u]);
            int poner = 0;
            if(used[v].empty() || *used[v].begin() != 0) poner = 0;
            else{
                used[v].erase(used[v].begin());
                if(used[v].empty() || *used[v].begin() != 1) poner = 1;
                else{
                    used[v].erase(used[v].begin());
                    if(used[v].empty() || *used[v].begin() != 2) poner = 2;
                    else poner = 3;
                }
            }

            a[v] = poner;
            q.push(v);
        }
    }
}

void solver(){
    int n, x, y; cin>>n>>x>>y;
    if(n == 3){
        cout<<"0 1 2"<<endl;
        return;
    }

    if(n == 4){
        vector<int> a(n+1, 1);
        if(x + 2 == y || (y + 2) % n == x){
            a[x] = 0;
            a[y] = 2;
        }
        else{
            for(int i = 1; i <= n; i += 2) a[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            if(i > 1) cout<<' ';
            cout<<a[i];
        }
        cout<<endl;

        return;
    }

    vector<int> a(n+1, -1);
    vector<int> graph[n+1];
    set<int> used[n+1];
    for(int i = 1; i <= n; i++){
        if(i == n) graph[i].pb(1);
        else graph[i].pb(i+1);
        if(i == 1) graph[i].pb(n);
        else graph[i].pb(i-1);
    }

    if(!(x + 1 == y || (y == n && x == 1))){
        graph[x].pb(y);
        graph[y].pb(x);
    }

    a[x] = 0; a[y] = 1;
    for(int v : graph[x]){
        used[v].insert(0);
    }
    for(int v : graph[y]){
        used[v].insert(1);
    }

    BFS(a, graph, used, x);

    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        cout<<a[i];
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