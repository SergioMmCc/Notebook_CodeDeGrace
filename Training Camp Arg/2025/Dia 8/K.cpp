#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int top=2e5, INF=1e9, MOD=1e9+7;
int vec[top+7];

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    set<int> work;
    int y;
    for(int i=0; i<k; i++){
        cin>>y;
        work.insert(y);
    }

    vector<vector<int>> gp(n+1);
    vector<pair<int, int>> deg(n+1);
    for(int i=1; i<=n; i++)deg[i].second = i;
    int u, v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        if(work.find(u) == work.end()){
            gp[u].push_back(v);  
            deg[u].first++;
        } 
        if(work.find(v) == work.end()){
            gp[v].push_back(u);  
            deg[v].first++;
        }
    }

    sort(deg.begin(), deg.end());
    vector<vector<int>> ans;
    vector<int> vis(n+1);
    queue<int> q;
    q.push(deg.back().second);
    vis[q.front()] = 1;
    while(!q.empty()){
        int x = q.front();
        ans.push_back({x});
        q.pop();

        for(int v : gp[x]){
            if(!vis[v]){
                ans.back().push_back(v);
                q.push(v);
                vis[v] = 1;
            }
        }
        if(ans.back().size() == 1) ans.pop_back();
    }

    bool flag=1;
    for(int i=1; i<=n; i++){
        flag &= vis[i];
    }

    if(!flag){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
    cout<<ans.size()<<"\n";
    for(vector<int>& i : ans){
        cout<<i[0]<<" "<<i.size()-1<<" ";
        for(int j=1; j<i.size(); j++){
            cout<<i[j]<<" ";
        }cout<<"\n";
    }

}

signed main(){
    solve();
    return 0;
}