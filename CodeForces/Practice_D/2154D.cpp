#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 1;
vector<set<int>> tree(maxn);

void BFS(int n, vector<int>& dis, vector<int>& pa){
    queue<int> q; q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(v == pa[u]) continue;
            pa[v] = u;
            dis[v] = (dis[u] + 1) % 2;
            q.push(v);
        }
    }
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) tree[i].clear();

    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].insert(v);
        tree[v].insert(u);
    }

    vector<int> dis(n+1), pa(n+1);
    BFS(n, dis, pa);
    vector<bool> walk(n+1); walk[n] = 1;
    vector<int> order;

    int u = n;
    while(u != 1){
        u = pa[u];
        order.pb(u);
        walk[u] = 1;
    }
    reverse(all(order));

    vector<set<int>> leafs(2);
    for(int i = 1; i <= n; i++){
        if(walk[i] || sz(tree[i]) > 1) continue;
        leafs[dis[i]].insert(i);
    }

    vector<pii> steps;

    int cnt = 1;
    while(!leafs[0].empty() || !leafs[1].empty()){
        if((!cnt && leafs[0].empty()) || (cnt && leafs[1].empty())){
            steps.pb({1, 0});
            cnt = (cnt + 1) % 2;
            continue;
        }

        int u = *leafs[cnt].begin();
        steps.pb({2, u});
        leafs[cnt].erase(u);

        for(int v : tree[u]){
            if(walk[v]) continue;
            tree[v].erase(u);
            if(sz(tree[v]) == 1) leafs[dis[v]].insert(v);
        }

        steps.pb({1, 0});
        cnt = (cnt + 1) % 2;
    }

    if(cnt == 1){
        steps.pb({1, 0});
        cnt = 0;
    }

    for(int i = 0; i < sz(order) - 1; i++){
        int u = order[i];
        steps.pb({2, u});
        steps.pb({1, 0});
        cnt = (cnt + 1) % 2;
    }

    cout<<sz(steps)<<endl;
    for(pii s : steps){
        cout<<s.fi;
        if(s.se) cout<<' '<<s.se;
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}