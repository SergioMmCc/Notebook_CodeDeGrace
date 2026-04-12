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

void DFS(int u, int n, vi& dp, vector<vi>& tree, bool op){
    if(dp[u] != -1) return;
    int sum = 0, mini = n;
    for(int v : tree[u]){
        DFS(v, n, dp, tree, op ^ 1);
        sum += dp[v];
        mini = min(mini, dp[v]);
    }

    if(op) dp[u] = mini;
    else dp[u] = sum;
}

void eval(int u, vb& ev, vector<vi>& tree, bool op){
    if(tree[u].empty()) return;
    bool opOr = 0, opAnd = 1;
    for(int v : tree[u]){
        eval(v, ev, tree, op ^ 1);
        opOr |= ev[v];
        opAnd &= ev[v];
    }

    if(op) ev[u] = opAnd;
    else ev[u] = opOr;
}

void solver(){
    int n; cin>>n;
    char st; cin>>st;
    bool op = st == 'A';

    vector<vi> tree;
    vi add; tree.pb(add);
    vii last;
    int x; cin>>x;
    last.pb({x, 0});
    int cnt = 0;
    vi dp;
    vb ev;
    ev.pb(0);
    dp.pb(-1);
    for(int i = 1; i < n; i++){
        int j = 0;
        vii remp;
        while(j < sz(last)){
            for(int k = 0; k < last[j].fi; k++){
                cnt++;
                tree.pb(add);
                tree[last[j].se].pb(cnt);
                dp.pb(-1);
                ev.pb(0);

                string re; cin>>re;
                if(re == "10"){
                    int b = 10;
                    remp.pb({b, cnt});
                }
                else if(re[0] - '0' >= 0 && re[0] - '0' <= 9){
                    int b = re[0] - '0';
                    remp.pb({b, cnt});
                }
                else{
                    dp[cnt] = re[0] == 'T' ? 1 : 0;
                    ev[cnt] = re[0] == 'T';
                }
            }

            j++;
        }

        swap(last, remp);
    }

    // for(int i = 0; i <= cnt; i++){cout<<i<<": ";
    //     for(int j : tree[i]) cout<<j<<", ";
    //     cout<<endl;
    // }

    eval(0, ev, tree, op);
    // for(int i = 0; i <= cnt; i++){
    //     cout<<"i -> "<<i<<" ev -> "<<ev[i]<<endl;
    // }
    if(!ev[0]){
        op ^= 1;
        for(int i = 0; i <= cnt; i++){
            if(dp[i] == 1) dp[i] = 0;
            else if(dp[i] == 0) dp[i] = 1;
        }
    }
    DFS(0, cnt, dp, tree, op);
    cout<<dp[0]<<endl;
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