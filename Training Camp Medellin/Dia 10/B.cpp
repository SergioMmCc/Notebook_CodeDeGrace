#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define db(x) cerr<< #x<<" "<<x<<endl
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


#define print(arr) for(auto val : arr){ cout << val << " "; } cout << '\n';

map<string, int> T = {{"Anka", 0}, {"Chapay", 1}, {"Cleo", 2}, {"Troll", 3}, {"Dracul", 4}, {"Snowy", 5}, {"Hexadecimal", 6}};
// vector<vi> perms = {{1, 2, 2, 3, 3, 3, 3}, {1, 1, 2, 2, 3, 3, 3}, {1, 2, 2, 2, 3, 3, 3}};
vector<vi> perms;

void solver(){
    int n; cin>>n;
    vector<vb> adj(7, vb(7));
    // cout<<T["Chapay"]<<endl;
    for(int i = 0; i < n; i++){
        string u, x, v; cin>>u>>x>>v;
        // cout<<"u -> "<<u<<" v -> "<<v<<endl;
        adj[T[u]][T[v]] = 1; 
    }

    vl p(4);
    for(int i = 1; i <= 3; i++) cin>>p[i];
    sort(all(p));

    pll ans = {1e15, 0};
    for(int i = 0; i < sz(perms); i++){
        vi perm = perms[i];
        int c1 = 0, c2 = 0, c3 = 0;
        for(int j = 0; j < 7; j++){
            if(perm[j] == 1) c1++;
            else if(perm[j] == 2) c2++;
            else c3++;
        }

        ll p1 = p[1] / (ll)c1, p2 = p[2] / (ll)c2, p3 = p[3] / (ll)c3;
        ll comp = max(p1, max(p2, p3)) - min(p1, min(p2, p3));
        // cout<<"comp -> "<<comp<<endl;
        if(comp > ans.fi) continue;
        if(comp < ans.fi) ans.se = 0;
        ans.fi = comp;

        do{
            int cnt = 0;
            vi v1, v2, v3;
            for(int j = 0; j < 7; j++){
                if(perm[j] == 1) v1.pb(j);
                else if(perm[j] == 2) v2.pb(j);
                else v3.pb(j);
            }

            for(int u : v1){
                for(int v : v1){
                    if(adj[u][v]) cnt++;
                }
            }
            for(int u : v2){
                for(int v : v2){
                    if(adj[u][v]) cnt++;
                }
            }
            for(int u : v3){
                for(int v : v3){
                    if(adj[u][v]) cnt++;
                }
            }

            // cout<<"cnt -> "<<cnt<<endl;

            ans.se = max(ans.se, (ll)cnt);
        } while(next_permutation(all(perm)));
    }

    cout<<ans.fi<<' '<<ans.se<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);


    for(int i = 1; i <= 7; ++i){
        for(int j = 1; i + j < 7; ++j){

            int k = 7 - i - j;

            vi perm;

            for(int ii = 0; ii < i; ++ii) perm.push_back(1);
            for(int ii = 0; ii < j; ++ii) perm.push_back(2);
            for(int ii = 0; ii < k; ++ii) perm.push_back(3);
            // print(perm);
            perms.push_back(perm);
        }
    }

    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}