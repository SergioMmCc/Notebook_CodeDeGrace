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

    if(n % k == 0){
        int r = 0;
        for(int i = 1; i <= n; i += k){
            vi aux;
            for(int j = i; j < i + k; j++){
                aux.pb(j);
            }
            r ^= ask(aux);
        }

        ans(r);
        return;
    }

    int div = 0, stop = 0;
    for(int res = n-k; !div && res > 0; res -= k, stop += k){
        for(int i = k-1; !div && i >= 1; i--){
            if(res % i == 0 && (res/i) % 2 == 0){
                // cout<<"i -> "<<i<<" res -> "<<res<<endl;
                div = i;
            }
        }
    }

    if(!div){
        cout<<-1<<endl;
        return;
    }

    // cout<<"here"<<endl;
    // cout<<"div -> "<<div<<" stop -> "<<stop<<endl;
    int r = 0;
    for(int i = 1; i <= stop; i += k){
        vi a;
        for(int j = i; j < i + k; j++){
            a.pb(j);
        }
        r ^= ask(a);
    }

    for(int i = stop + 1; i <= n; i += div){
        vi a;
        for(int j = 1; j <= k-div; j++) a.pb(j);
        for(int j = i; j < i+div; j++) a.pb(j);

        r ^= ask(a);
    }

    ans(r);
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