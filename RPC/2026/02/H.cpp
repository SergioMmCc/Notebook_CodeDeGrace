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

void solver(){
    int n; ll k, d, s; cin>>n>>k>>d>>s;
    vl a(n), ps(2*n), sum(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        ps[i] = a[i];
        if(i) ps[i] += ps[i-1];
    }
    for(int i = n; i < 2*n; i++) ps[i] = a[i-n] + ps[i-1];
    for(int i = 0; i < n; i++) sum[i] = ps[s + i - 1] - (i ? ps[i-1] : 0);

    vi trans(n);
    vector<vi> ciclos;
    vl sumCiclo;

    for(int i = 0; i < n; i++){
        int j = (i + (k % n)) % n;
        trans[i] = j;
    }

    vb vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int u = i;
        vi add;
        ll cnt = 0;
        while(!vis[u]){
            vis[u] = 1;
            add.pb(u);
            cnt += sum[u];
            u = trans[u];
        }
        ciclos.pb(add);
        sumCiclo.pb(cnt);
    }

    vector<vl> psCiclo(sz(ciclos));
    for(int i = 0; i < sz(ciclos); i++){
        for(int j = 0; j < sz(ciclos[i]); j++){
            psCiclo[i].pb(sum[ciclos[i][j]]);
            if(j) psCiclo[i][j] += psCiclo[i][j-1];
        }
        for(int j = 0; j < sz(ciclos[i]); j++){
            psCiclo[i].pb(psCiclo[i][sz(psCiclo[i]) - 1] + sum[ciclos[i][j]]);
        }
    }

    vi st(n, n);
    queue<int> q;
    for(int i = 0; i <= n-s; i++){
        st[i] = 0;
        q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(st[trans[u]] == n){
            st[trans[u]] = trans[u] + 1;
            q.push(trans[u]);
        }
    }

    ll ans = -1e18;
    for(int i = 0; i < sz(ciclos); i++){
        ll extra = sumCiclo[i] * (d / (ll)sz(ciclos[i]));
        for(int j = 0; j < sz(ciclos[i]); j++){
            if(st[ciclos[i][j]] <= n-d && (d % (ll)sz(ciclos[i]))){
                ll aux = extra + psCiclo[i][j + ((d % (ll)sz(ciclos[i]))) - 1] - (j ? psCiclo[i][j-1] : 0);
                ans = max(aux, ans);
            }
            else if(st[ciclos[i][j]] <= n-d) ans = max(ans, extra);

            st[trans[ciclos[i][j]]] = min(st[trans[ciclos[i][j]]], st[ciclos[i][j]] + 1);
        }
    }

    cout<<ans<<endl;
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