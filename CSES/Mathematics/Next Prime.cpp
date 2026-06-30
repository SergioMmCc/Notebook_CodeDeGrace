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

map<ll, ll> save;

void solver(){
    ll n; cin>>n;
    auto aux = save.ub(n);
    if(aux != save.begin()){
        --aux;
        if(aux->se > n){
            cout<<aux->se<<endl;
            return;
        }
    }

    ll copy = n;
    while(1){
        n++;
        if(save.find(n) != save.end()){
            cout<<save[n]<<endl;
            return;
        }
        bool cond = 1;
        for(ll i = 2; cond && i * i <= n; i++) if(n % i == 0) cond = 0;
        if(cond){
            save[copy] = n;
            cout<<n<<endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}