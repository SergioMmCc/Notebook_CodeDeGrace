#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver(){
    int n, m;
    cin>>n>>m;
    vector<int> dir[n], ndir[n+1];
    for(int i = 1; i < n; i++){
        dir[i].push_back(i+1);
        ndir[i+1].push_back(i);
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        dir[u].push_back(v);
        ndir[v].push_back(u);
    }
    
    int totalJumps = 0;
    vector<int> jump(n+1);
    for(int u = 0; u < n-1; u++){
        for(int v : ndir[u]) jump[u] = max(jump[u], jump[v] + u - v - 1);
        for(int v : dir[u]) totalJumps = max(totalJumps, jump[u] + v - u - 1);
        if(totalJumps > u)cout<<0;
        else cout<<1;
    }
    cout<<endl;
}

int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }
    
    return 0;
}