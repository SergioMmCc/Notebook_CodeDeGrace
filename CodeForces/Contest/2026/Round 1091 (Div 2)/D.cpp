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
    int n, k; cin>>n>>k;
    vi a(n+2);
    for(int i = 1; i <= n; i++) cin>>a[i];
   
    vb mark(n+1);
    int col = 0;
    for(int i = 0; i < k; i++){
        int aux; cin>>aux;
        col = a[aux];
        mark[aux] = 1;
    }

    for(int i = 1; i <= n; i++) a[i] = (a[i] == col ? 0 : 1);
    
    int tot = 0, maxx = 0, parc = 0;
    for(int i = 0; i <= n+1; i++){
        if(mark[i] || i == n+1){
            maxx = max(maxx, parc);
            parc = 0;
        }
        if(i <= n && a[i] != a[i+1]){
            tot++;
            parc++;
        }
    }

    cout<<max(maxx, (tot+1) / 2)<<endl;
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