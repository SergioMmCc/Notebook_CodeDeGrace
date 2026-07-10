#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
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

const int K = 20;
const ll inf = 1e18;
struct RMQ{
    ll neutro = -inf;
    vector<vl> st;
    inline ll oper(ll a, ll b){ return a > b ? a : b;}

    RMQ(vl& a){
        st = vector<vl> (sz(a), vl(K));
        for(int i = 0; i < sz(a); i++)st[i][0] = a[i];
        for(int j = 1; j <= K-1; j++){
            for(int i = 0; i < sz(a) - (1 << j) + 1; i++){
                st[i][j] = oper(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    };

    ll query(int l, int r){
        if(l > r) return neutro;
        int j = 31 - __builtin_clz(r-l+1);
        return oper(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

struct RMQmin{
    ll neutro = inf;
    vector<vl> st;
    inline ll oper(ll a, ll b){ return a < b ? a : b;}

    RMQmin(vl& a){
        st = vector<vl> (sz(a), vl(K));
        for(int i = 0; i < sz(a); i++)st[i][0] = a[i];
        for(int j = 1; j <= K-1; j++){
            for(int i = 0; i < sz(a) - (1 << j) + 1; i++){
                st[i][j] = oper(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    };

    ll query(int l, int r){
        if(l > r) return neutro;
        int j = 31 - __builtin_clz(r-l+1);
        return oper(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

void solver(){
    int n, q; cin>>n>>q;
    vl a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];
    vl dif(n+1);
    for(int i = 1; i <= n; i++) dif[i] = a[i] - b[i];

    vl pd(n+1);
    for(int i = 1; i <= n; i++){
        pd[i] = pd[i-1] + dif[i];
    }

    RMQ x(pd);
    RMQmin y(pd);

    while(q--){
        int l, r; cin>>l>>r;
        // cout<<pd[r]<<' '<<pd[l-1]<<' '<<l<<' '<<r<<endl;
        // int aux = x.query(l, r) + pd[l-1];
        // db(x.query(l, r));
        if(pd[r] - pd[l-1] != 0 || x.query(l, r) - pd[l-1] > 0){
            cout<<-1<<endl;
            continue;
        }

        // db(y.query(l, r));
        // db(x.query(l, r));
        // db(pd[l-1]);
        cout<<max(abs(y.query(l, r) - pd[l-1]), abs(x.query(l, r) - pd[l-1]))<<endl;
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