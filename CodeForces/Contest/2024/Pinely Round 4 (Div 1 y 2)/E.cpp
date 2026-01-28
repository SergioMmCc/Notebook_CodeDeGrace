#include<bits/stdc++.h>
using namespace std;
const int MAXT = 1e4 + 1;
vector<int> g[MAXT];
vector<int> color(MAXT), visited(MAXT);
queue<int> q;

bool BFS(int n) {
    for(int i = 1; i <= n; i++)
        visited[i] = 0;
    while(!q.empty())
        q.pop();
    
    q.push(1);
    color[1] = 1;
    visited[1] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(color[u] == 1) {
                if(color[v] == 1)
                    return false;
                color[v] = 2;
            }
            else if(color[u] == 2) {
                if(color[v] == 2)
                    return false;
                color[v] = 1;
            }
            if(visited[v] == 0) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return true;
}

void solver() {
    int n, m;cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        color[i] = 0;
    }
        
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool who = BFS(n);
    if(who) {
        vector<int> color1, color2;
        for(int i = 1; i <= n; i++) {
            if(color[i] == 1) 
                color1.push_back(i);
            else
                color2.push_back(i);
        }
        cout<<"Bob"<<endl;
        int count = 0;

        while(count < n) {
            count++;
            int a, b;cin>>a>>b;
            if(!color1.empty()) {
                if (a == 1 || b == 1) {
                    cout<<color1.back()<<" 1"<<endl;
                    color1.pop_back();
                }
                else if(!color2.empty()) {
                    cout<<color2.back()<<" 2"<<endl;
                    color2.pop_back();
                }
                else {
                    cout<<color1.back()<<" 3"<<endl;
                    color1.pop_back();
                }
            }
            else {
                if(a > 1) 
                    cout<<color2.back()<<" "<<a<<endl;
                else
                    cout<<color2.back()<<" "<<b<<endl;
                color2.pop_back();
            }
        }
    }
    else {
        cout<<"Alice"<<endl;
        for(int j = 0; j < n; j++) {
            cout<<"1 2"<<endl;
            int i, c;
            cin>>i>>c;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }
}