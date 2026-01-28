#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

const int maxn = 1e5;
vector<vector<int>> tree(maxn);

ld strToLD(string s){
    ld aux = 1.0, ans = 0.0;
    int len = s.sz;
    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        int num = s[i] - '0';
        ans += (ld)num * aux;
        aux *= 0.1;
    }

    return ans;
}

ld BFS(int n, vector<int>& pa, vector<ld>& sons, vector<ld>& p){
    ld ans = 0;
    vector<bool> vis(n); vis[0] = 1;
    queue<int> q; q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans += p[u];

        for(int v : tree[u]){
            if(vis[v]) continue;
            pa[v] = u;
            sons[u] += p[v];
            q.push(v);
            vis[v] = 1;
        }

        ans -= p[u] * sons[u];
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    vector<ld> p(n), sons(n); vector<int> pa(n, -1);
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        ld aux = strToLD(s);
        p[i] = 1.0 - aux;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    ld ans = BFS(n, pa, sons, p);

    int q; cin>>q;
    while(q--){
        int u; string s; cin>>u>>s;
        ld aux = strToLD(s);
        aux = 1.0 - aux;

        // Actualizar
        ans = ans + aux - p[u] + p[u] * sons[u] - aux * sons[u];
        if(u){
            int v = pa[u];
            ans += sons[v] * p[v];
            sons[v] = sons[v] + aux - p[u];
            ans -= sons[v] * p[v];
        }

        p[u] = aux;

        cout<<fixed<<setprecision(10)<<ans<<endl;
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