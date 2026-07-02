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

bool check(int n, int m, ll k, vl a){
    int last = 0;
    for(int i = 0; i < m; i++){
        ll aux = k;
        aux -= last;
        while(aux > 0){
            if(aux < a[last]){
                a[last] -= aux;
                break;
            }
            if(last == n && aux >= a[n]) return 1;
            aux -= a[last];
            aux--;
            last++;
        }
    }

    return 0;
}

void solver(){
    int n, m; cin>>n>>m;
    vl a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    while(!a.back()){
        n--;
        a.pop_back();
    }

    ll l = n+1, r = 1e18;
    while(l < r){
        ll k = (l + r) / 2;
        if(check(n, m, k, a)) r = k;
        else l = k+1;
    }

    cout<<l<<endl;
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