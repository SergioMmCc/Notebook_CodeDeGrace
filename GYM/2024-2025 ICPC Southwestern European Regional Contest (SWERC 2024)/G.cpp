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
    ll r; int n; cin>>r>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    // Desde 0 llega a R
    bool cond = 0;
    ll pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) pos = max(0LL, pos + a[i]);
        else pos = min(r, pos + a[i]);
        if(pos == r) cond = 1;
    }
    if(cond){
        cout<<pos<<endl;
        return;
    }

    // Desde R llega a 0
    pos = r;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) pos = max(0LL, pos + a[i]);
        else pos = min(r, pos + a[i]);
        if(pos == 0) cond = 1;
    }
    if(cond){
        cout<<pos<<endl;
        return;
    }
    cout<<"uncertain"<<endl;
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