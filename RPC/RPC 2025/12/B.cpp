#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    ll d; cin>>d;
    ll a, b; cin>>a>>b;
    ll da, db; cin>>da>>db;

    ll ra = max(0LL, a - d*da);
    ll rb = max(0LL, b - d*db);

    ll tot = ra + rb;

    ld ans = (ld)ra / (ld)tot;
    ans *= 100.0;
    cout<<fixed<<setprecision(8)<<ans<<endl;
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