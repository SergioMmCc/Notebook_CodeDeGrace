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
    ll l, r; cin>>l>>r;
    if(l == r){
        cout<<l<<endl<<l<<endl;
        return;
    }
    ll st = l;
    int n = r - l + 1;
    vector<ll> ans(n);
    ll num = 1 << 29;
    while(num > 0LL){
        bool c0 = 0, c1 = 0;
        for(ll i = l; !c1 && i <= r; i++){
            if(!(i & num)){
                c0 = 1;
                continue;
            }
            c1 = 1;
            if(c0){
                ll x = i-1, y = i;
                while(x >= l && y <= r){
                    ans[x - st] = y;
                    ans[y - st] = x;
                    x--;
                    y++;
                }

                if(x < l) l = y;
                if(y > r) r = x;
                if(l >= r) num = 0;
                if(l == r) ans[l - st] += l;
            }
        }
        num >>= 1;
    }

    ll cnt = 0;
    for(int i = 0; i < n; i++) cnt += ans[i] | ((ll)i + st);
    cout<<cnt<<endl;
    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
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