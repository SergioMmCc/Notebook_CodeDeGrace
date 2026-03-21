#include <bits/stdc++.h> 
using namespace std;
const int top=1e5;
bool v[top + 7];
bool visited[top + 7];
int val[top + 7];

int main(){
    ios::sync_with_stdio(0);cin.tie(NULL);
    
    int n, m; 
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    vector<vector<int>> arbol(n+1);

    int x, y;
    for(int i=1; i<n; i++){
        cin>>x>>y;

        arbol[x].push_back(y);       
        arbol[y].push_back(x);       
    }

    stack<int> s;
    s.push(1);
    int c=0; val[1] = v[1];

    while(!s.empty()){
        int u = s.top();
        s.pop();

        if(val[u] > m) continue;

        if(!visited[u]){
            bool leaf=1;

            visited[u] = 1;
            for(int& i : arbol[u]){
                if(!visited[i]){
                    leaf = 0;
                    s.push(i);
                    val[i] = (v[i] == 1)? val[u] + v[i] : 0;
                }
            }
            if(leaf && val[u] <= m)c++;
        }
    }

    cout<<c<<'\n';
    return 0;
}