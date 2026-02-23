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
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

pii BFS(int n, vector<vi>& tree, vector<vi>& level, vi& pa, vector<vi>& sons){
    pa[1] = -1;
    level[0].pb(1);
    queue<int> q; q.push(1);
    vi lev(n+1);
    vb vis(n+1); vis[1] = 1;
    pii ans = {1, 0};
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : tree[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            lev[v] = lev[u]+1;
            level[lev[v]].pb(v);
            ans = max(ans, {sz(level[lev[v]]), lev[v]});
            pa[v] = u;
            sons[u].pb(v);
            q.push(v);
        }
    }

    return ans;
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1), level(n);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vi pa(n+1);
    vector<vi> sons(n+1);
    pii aux = BFS(n, tree, level, pa, sons);
    int cnt = aux.fi, st = aux.se;

    vector<vi> ans(cnt);
    vi seg(n+1);
    // Nivel aux
    for(int i = 0; i < cnt; i++){
        ans[i].pb(level[st][i]);
        seg[level[st][i]] = i;
    }

    // Los niveles de abajo
    for(int k = st+1; k < n; k++){
        if(level[k].empty()) break;

        set<int> av;
        for(int i = 0; i <= sz(level[k]); i++) av.insert(i);

        for(int u : level[k]){
            int l = *av.begin();
            if(l == seg[pa[u]]) l = *av.rbegin();
            av.erase(l);
            ans[l].pb(u);
            seg[u] = l;
        }
    }

    // Los niveles de arriba
    for(int k = st-1; k >= 0; k--){
        int cond = 0;
        if(sz(ans) == cnt && sz(level[k+1]) == cnt) for(int i = 0; !cond && i < sz(level[k]); i++) if(sz(sons[level[k][i]]) == cnt) cond = level[k][i];
        if(cond){
            vi x = {cond};
            seg[cond] = sz(ans);
            ans.pb(x);
            int i = 0;
            for(int j = 0; j < sz(level[k]); j++){
                if(level[k][j] == cond) continue;
                ans[i].pb(level[k][j]);
                seg[level[k][j]] = i;
                i++;
            }
        }

        else{
            vi pad;
            for(int u : level[k]) if(sz(sons[u])) pad.pb(u);
            if(sz(pad) == 1){ // Solo uno tiene hijos
                set<int> sk;
                for(int s : sons[pad[0]]) sk.insert(seg[s]);
                int l = -1;
                for(int i = 0; l == -1 && i < sz(ans); i++) if(sk.find(i) == sk.end()) l = i;
                ans[l].pb(pad[0]);
                seg[pad[0]] = l;
                int i = 0;
                for(int u : level[k]){
                    if(u == pad[0]) continue;
                    if(i == l) i++;
                    ans[i].pb(u);
                    seg[u] = i;
                    i++;
                }
            }

            else{
                set<int> sk;
                for(int i = 0; i < sz(pad); i++){
                    int u = pad[i], v = (i ? pad[i-1] : pad[sz(pad) - 1]);
                    int l = seg[sons[v][0]];
                    ans[l].pb(u);
                    seg[u] = l;
                    sk.insert(l);
                }

                int i = 0;
                for(int u : level[k]){
                    if(sz(sons[u])) continue;
                    while(sk.find(i) != sk.end()) i++;
                    ans[i].pb(u);
                    seg[u] = i;
                    i++;
                }
            }
        }
    }

    // Respuesta
    cout<<sz(ans)<<endl;
    for(int i = 0; i < sz(ans); i++){
        cout<<sz(ans[i]);
        for(int u : ans[i]) cout<<' '<<u;
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