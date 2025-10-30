#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
typedef pair<bool, pii> pbii;

const int maxn = 50005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn);
vector<int> sets[maxn];

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

void solver(){
    int n, m, q; cin>>n>>m>>q;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
    }
    initDSU(n);
    stack<pbii> st;
    while(q--){
        string op; int u, v; cin>>op>>u>>v;
        st.push({op == "ask" ? 0 : 1, {u, v}});
    }

    stack<bool> ans;
    while(!st.empty()){
        bool op = st.top().first;
        int u = st.top().second.first, v = st.top().second.second;
        st.pop();
        if(!op) ans.push(leader[u] == leader[v] ? 1 : 0);
        else join(u, v);
    }

    while(!ans.empty()){
        cout<<(ans.top() ? "YES" : "NO")<<endl;
        ans.pop();
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