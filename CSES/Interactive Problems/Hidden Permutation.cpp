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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
int cnt = 0;
 
bool ask(int i, int j){
    cnt++;
    assert(cnt <= 10000);
    cout<<"? "<<i<<' '<<j<<endl;
    string r; cin>>r;
    return r == "YES";
}
 
void ans(vi& a){
    cout<<'!';
    for(int i = 1; i < sz(a); i++){
        cout<<' '<<a[i];
    }
    cout<<endl;
}
 
void merge(int i, int j, vi& rev){
    if(i >= j) return;
    int mid = i + (j-i+1) / 2;
    merge(i, mid-1, rev);
    merge(mid, j, rev);
 
    int l = i, r = mid;
    vi order;
    while(l < mid && r <= j){
        bool cond = ask(rev[l], rev[r]);
        if(cond){
            order.pb(rev[l]);
            l++;
        }
        else{
            order.pb(rev[r]);
            r++;
        }
    }
 
    if(l >= mid) for(; r <= j; r++) order.pb(rev[r]);
    if(r > j) for(; l < mid; l++) order.pb(rev[l]);
 
    for(int k = i; k <= j; k++){
        rev[k] = order[k - i];
    }
}
 
void solver(){
    int n; cin>>n;
    vi rev(n+1);
    for(int i = 1; i <= n; i++) rev[i] = i;
 
    merge(1, n, rev);
 
    vi perm(n+1);
    for(int i = 1; i <= n; i++) perm[rev[i]] = i;
    ans(perm);
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