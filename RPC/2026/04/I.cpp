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
    int n, m; cin>>n>>m;
    vector<vi> a(n+1), b(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        b[u].pb(v);
        a[v].pb(u);
    }

    pii ans = {1, 0};
    for(int i = 1; i <= n; i++){
        sort(all(a[i]));
        sort(all(b[i]));

        int cnt = 0;
        int idx = 0, jdx = 0;
        while(idx < sz(a[i])){
            // cout<<i<<' '<<
            // cout<<"cnt -> "<<cnt<<" idx -> "<<idx<<" jdx -> "<<jdx<<endl;
            // <<" a -> "<<a[i][idx]<<" jdx -> "<<jdx<<" b -> "<<b[i][jdx]<<endl;
            if(jdx >= sz(b[i])){
                cnt++;
                idx++;
                continue;
            }
            if(a[i][idx] < b[i][jdx]){
                cnt++;
                idx++;
            }
            else if(a[i][idx] == b[i][jdx]){
                idx++;
                jdx++;
            }
            else{
                jdx++;
            }
        }
        // cout<<"i -> "<<i<<" cnt -> "<<cnt<<endl;
        if(cnt > ans.se) ans = {i, cnt};
    }

    cout<<ans.fi<<' '<<ans.se<<endl;
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