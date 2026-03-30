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

const int mod = 676767677;

void solver(){
    int x, y; cin>>x>>y;
    int n = x+y;
    if(!x || !y){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(n % i == 0) ans++;
        }

        cout<<ans<<endl;
        for(int i = 1; i <= n; i++) cout<<(x ? 1 : -1)<<' ';
        cout<<endl;
        return;
    }

    int ans = 1;
    vi pri(n);
    for(int i = 1; i <= n; i++) pri[i-1] = i <= x ? 1 : -1;

    if(y > x) swap(x, y);
    int sumr = -y;
    for(int i = n - y - 1; i > 0; i--){
        sumr++;
        if(sumr > 0 && i % sumr == 0){
            ans++;
        }
    }

    cout<<ans<<endl;
    for(int i = 1; i <= n; i++) cout<<pri[i-1]<<' ';
    cout<<endl;
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