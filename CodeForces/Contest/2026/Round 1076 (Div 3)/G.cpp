#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

bool ask(int a, int b){
    cout<<"? "<<a<<' '<<b<<endl;
    bool ans; cin>>ans;
    return ans;
}

void ans(int v){
    cout<<"! "<<v<<endl;
}

void BFS(int n, vector<vi>& tree){
    queue<int> q; q.push(1);
    vector<bool> vis(n+1); vis[1] = 1;

    int a = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(!a) a = u;
        else{
            if(ask(a, u)){
                if(ask(a, a)) ans(a);
                else ans(u);
                return;
            }

            a = 0;
        }

        for(int v : tree[u]){
            if(vis[v]) continue;
            q.push(v);
            vis[v] = 1;
        }
    }

    ans(a);
}

void solver(){
    int n; cin>>n;
    vector<vi> tree(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    BFS(n, tree);
}
 
int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}