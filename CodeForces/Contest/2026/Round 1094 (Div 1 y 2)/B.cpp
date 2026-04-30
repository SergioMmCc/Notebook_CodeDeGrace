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
    int n, m; cin>>n>>m;
    vi pa, im;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int num; cin>>num;
        sum += (ll)num;
        if(i & 1) im.pb(num);
        else pa.pb(num);
    }

    int ci = 0, cp = 0;
    for(int i = 0; i < m; i++){
        int num; cin>>num;
        if(num & 1) ci++;
        else cp++;
    }

    sort(all(pa)); reverse(all(pa));
    sort(all(im)); reverse(all(im));

    if(ci) sum -= (ll)im[0];
    if(n > 1 && cp) sum -= (ll)pa[0];

    for(int i = 1; i < sz(im) && i < ci; i++){
        if(im[i] <= 0) break;
        sum -= (ll)im[i];
    }
    for(int i = 1; i < sz(pa) && i < cp; i++){
        if(pa[i] <= 0) break;
        sum -= (ll)pa[i];
    }

    cout<<sum<<endl;
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