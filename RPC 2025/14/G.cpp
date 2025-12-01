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
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    vector<int> ps(n+1);
    vector<ll> freq(4e5 + 2);

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > a[i-1]) ps[i] = ps[i-1] + 1;
        else ps[i] = ps[i-1] - 1;

        freq[ps[i] + 2e5]++;
    }

    ll ans = 0;
    for(int i = 0; i < sz(freq); i++) ans += (freq[i] * (freq[i] + 1)) / 2;
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