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
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> pli;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<pli>> rmq;

// Llenar sparse table
// O(nlg(n))
void fillRMQ(vector<int>& a){
    int n = sz(a); rmq.resize(n);
    int lgn = 31 - __builtin_clz(n); // Piso del log2 de n

    for(int i = 0; i < n; i++){
        rmq[i].resize(lgn + 1);
        rmq[i][0] = {a[i], i};
    }

    for(int j = 1; j <= lgn; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
}

pli query(int l, int r){
    if(l > r) return {0, 0};
    int lg = 31 - __builtin_clz(r - l + 1); // Piso del Log2 del tamaño del rango
    return min(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]); // [l, r]
}

void solver(){
    ll n; cin>>n;
    vector<int> v1(n), v2(n);
    vector<vector<int>> idx1(2*n + 1), idx2(2*n+1);
    for(int i = 0; i < n; i++){
        cin>>v1[i];
        idx1[v1[i]].pb(i);
    }
    for(int i = 0; i < n; i++){
        cin>>v2[i];
        idx2[v2[i]].pb(i);
    }

    vector<int> pm(n); pm[0] = v1[0];
    for(int i = 1; i < n; i++) pm[i] = max(pm[i-1], v1[i]);

    vector<int> sb(n); sb[n-1] = v2[n-1];
    for(int i = n - 2; i >= 0; i--) sb[i] = max(sb[i+1], v2[i]);

    vector<int> bigg(n);
    for(int i = 0; i < n; i++) bigg[i] = max(pm[i], sb[i]);

    fillRMQ(bigg);

    ll ans = 0;
    int mini = n, maxi = -1;
    for(int i = 1; i <= v1[0]; i++){

        int add = 2*n - query(maxi + 1, mini - 1).fi + 1;
        ans += (ll)add;


        for(int x : idx1[i]) mini = min(mini, x);
        for(int x : idx2[i]) maxi = max(maxi, x);

        if(maxi + 1 > mini - 1) break;
    }

    cout<<ans<<endl;
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