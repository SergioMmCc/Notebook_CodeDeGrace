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
    int n, q; cin>>n>>q;
    multiset<int> b;
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        b.insert(num);
        if(sz(b) > 30) b.erase(b.begin());
    }
    for(int i = n; i < 30; i++) b.insert(0);

    while(q--){
        int num; cin>>num;
        ll ans = 0;
        multiset<int> a = b;
        for(int i = 29; i >= 0; i--){
            int bit = (1 << i);
            if(!(num & bit)) continue;
            int add = *a.rbegin();
            if(add < bit) ans += bit - add;
            else if(add > bit) a.insert(add - bit);
            auto it = a.end(); --it;
            a.erase(it);
        }

        cout<<ans<<endl;
    }
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