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

void ans(vii& edj){
    cout<<"! "<<sz(edj)<<endl;
    for(pii e : edj) cout<<e.fi<<' '<<e.se<<endl;
}

vi ask(int k){
    cout<<"? "<<k<<endl;
    int q; cin>>q;
    vi a(q);
    for(int i = 0; i < q; i++) cin>>a[i];
    return a;
}

int go(vi &cnt, int n, vector<vi> &sons, int u){
    if(cnt[u]) return cnt[u];

    cnt[u] = 1;
    for(int v : sons[u]) cnt[u] += go(cnt, n, sons, v);
    return cnt[u];
}

void solver(){
    int n; cin>>n;

    int k = 2;
    vi cnt(n+1);
    vector<vi> sons(n+1);
    vb vis(n+1); vis[1] = 1;
    vii edj;

    while(1){
        vi aux = ask(k);
        if(aux.empty()) break;
        
        int v = aux[sz(aux) - 1];

        if(sz(aux) > 1){
            int u = aux[sz(aux) - 2];
            edj.pb({u, v});
            sons[u].pb(v);
        }

        if(vis[v]){
            
            go(cnt, n, sons, v);
            k += cnt[v];

            continue;
        }

        vis[v] = 1;
        k++;
    }

    ans(edj);
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