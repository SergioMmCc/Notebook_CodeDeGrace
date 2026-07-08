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

int ask(vi& a){
    cout<<"?";
    for(int x : a) cout<<' '<<x;
    cout<<endl;
    int r; cin>>r;
    return r;
}

void ans(int x){
    cout<<"! "<<x<<endl;
}

void solver(){
    int n, k; cin>>n>>k;

    vector<vii> graph(n+1);
    for(int s1 = 0; s1 < n; s1++){
        int s2 = n - s1;
        for(int r = 0; r <= k; r++){
            int l = k - r; // l es la cantidad de unos que voy a tomar
            int a1 = s1 + r - l;
            if(l <= s1 && r <= s2 && a1 >= 0 && a1 <= n) graph[s1].pb({a1, l});
        }
    }

    queue<int> q;
    q.push(0);
    vii pa(n+1, {-1, -1});
    vb vis(n+1); vis[0] = 1;
    while(!vis[n] && !q.empty()){
        int u = q.front(); q.pop();
        for(pii e : graph[u]){
            int v = e.fi, l = e.se;
            if(vis[v]) continue;
            pa[v] = {u, l};
            vis[v] = 1;
            if(v == n) break;
            q.push(v);
        }
    }

    if(!vis[n]){
        cout<<-1<<endl;
        return;
    }

    stack<pii> st;
    int aux = n;
    while(aux != -1){
        st.push({aux, pa[aux].se});
        aux = pa[aux].fi;
    }

    int res = 0;
    vb grade(n+1);
    int u = st.top().fi; st.pop();
    while(!st.empty()){
        vi a;
        int v = st.top().fi, l = st.top().se; st.pop();
        int r = k - l;
        for(int i = 1; i <= n; i++){
            if(grade[i] && l){
                a.pb(i);
                l--;
                grade[i] = 0;
            }
            else if(!grade[i] && r){
                a.pb(i);
                r--;
                grade[i] = 1;
            }
        }
        res ^= ask(a);

        u = v;
    }

    ans(res);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}