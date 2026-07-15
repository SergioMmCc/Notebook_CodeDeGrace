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

const ll mod = 1e9 + 7;

const int maxn = 200005;
int components;
vector<int> graph[maxn];
vector<int> leader(maxn), sizen(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(leaderU != leaderV){
        if(sizen[leaderV] > sizen[leaderU])
            swap(leaderU, leaderV);
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        components--;
    }
}

void solver(){
    int n; cin>>n;
    initDSU(n);
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        join(i, num);
    }

    map<int, int> calc;
    for(int i = 1; i <= n; i++){
        if(find(i) != i) continue;
        int num = sizen[i];
        map<int, int> add;
        for(int x = 2; x*x <= num; x++){
            while(num % x == 0){
                add[x]++;
                num /= x;
            }
        }
        if(num > 1) add[num]++;
        for(const auto& par : add){
            if(calc.find(par.fi) == calc.end()) calc[par.fi] = par.se;
            else calc[par.fi] = max(calc[par.fi], par.se);
        }
    }

    ll ans = 1;
    for(const auto& par : calc){
        for(int i = 0; i < par.se; i++){
            ans = (ans * (ll)par.fi) % mod;
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