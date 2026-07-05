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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int logq = 19;

void solver(){
    int q; cin>>q;
    vi depth(q), root(q); root[1] = 1;
    vl w(q), cost(q);
    vector<vi> up(q, vi(logq));
    int ans = 0;
    int u = 2;

    while(q--){
        int op, v; ll k; cin>>op>>v>>k;
        v ^= ans;
        k ^= ans;

        if(op == 1){ // Add vertex
            w[u] = k;

            if(w[root[v]] < k){
                root[u] = u;
                cost[u] = k;
                u++;
                continue;
            }
            
            if(w[v] < w[u]){
                while(w[up[v][0]] < w[u]){
                    int go = 1;
                    while(w[up[v][go]] < k){
                        if(!w[up[v][go]]) break;
                        go++;
                    }

                    v = up[v][go-1];
                }

                v = up[v][0];
            }

            up[u][0] = v;
            depth[u] = depth[v] + 1;
            root[u] = root[v];
            cost[u] = cost[v] + k;
            for(int i = 1; i < logq; i++) up[u][i] = up[up[u][i-1]][i-1];

            u++;
        }
        else{ // Query
            if(w[v] > k){
                ans = 0;
                cout<<ans<<endl;
                continue;
            }
            if(cost[v] <= k){
                ans = depth[v] + 1;
                cout<<ans<<endl;
                continue;
            }

            int node = v;
            while(cost[v] - cost[up[node][1]] <= k){
                int go = 1;
                while(cost[v] - cost[up[up[node][go]][0]] <= k){
                    go++;
                }
                go--;
                node = up[node][go];
            }

            ans = depth[v] - depth[node] + 1;
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}