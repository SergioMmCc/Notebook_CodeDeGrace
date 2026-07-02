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

const ll mod = 1e9 + 7;

ll proc(int s, vi& graph, vi& a, vb& vis){
    ll sum = 0;
    int prof = 0;
    stack<int> aux;
    while(s){
        vis[s] = 1;
        aux.push(s);
        sum += (ll)prof * a[s];
        prof++;
        s = graph[s];
    }

    ll add = 0;
    while(!aux.empty()){
        a[aux.top()] += add;
        add = a[aux.top()];
        aux.pop();
    }

    return sum;
}

void solver(){
    int n, m; ll t; cin>>n>>m>>t;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    vi graph(n+1), inDegree(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        graph[v] = u;
        inDegree[u]++;
    }

    vb vis(n+1);
    for(int i = 1; i <= n; i++){
        if(graph[i] && !inDegree[i]){
            t -= proc(i, graph, a, vis);
            if(t < 0){
                cout<<0<<endl;
                return;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if((inDegree[i] || graph[i]) && !vis[i]){
            cout<<0<<endl;
            return;
        }
    }

    vl dp(t+1); dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j <= t; j++){
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }

    cout<<dp[t]<<endl;
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