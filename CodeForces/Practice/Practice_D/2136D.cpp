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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll esq = 1000000000;

ll ask(char d, ll w){
    cout<<"? "<<d<<' '<<w<<endl;
    ll a; cin>>a;
    return a;
}

void ans(ll x, ll y){
    cout<<"! "<<x<<' '<<y<<endl;
}

void solver(){
    int n; cin>>n;
    ll x1 = -esq, y1 = -esq, x2 = -esq, y2 = esq;
    for(int i = 0; i < n; i++){
        ll e, f; cin>>e>>f;
        if(e + f >= x1 + y1) x1 = e, y1 = f;
        if(f - e <= y2 - x2) x2 = e, y2 = f;
    }

    ask('R', esq);
    ask('R', esq);
    ask('U', esq);
    ll d1 = ask('U', esq);
    ask('D', esq);
    ask('D', esq);
    ask('D', esq);
    ll d2 = ask('D', esq);

    ll a = (d1 + d2 + x1 + x2 + y1 - y2)/2 - 4*esq;
    ll b = (d1 - d2 + x1 - x2 + y1 + y2)/2;
    ans(a, b);
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