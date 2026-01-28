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
    int n; cin>>n;
    ll a = 0, b = 0;
    map<ll, ll> freq;
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        a += num / 2;
        b += num / 2;
        if(num % 2){
            freq[num]++;
        }
    }

    vector<ll> add;
    for(const auto& par: freq) add.pb(par.se);
    sort(add.begin(), add.end());
    reverse(add.begin(), add.end());
    for(int i = 0; i < add.sz; i++){
        if(i % 2) b += add[i];
        else a += add[i];
    }

    cout<<a<<' '<<b<<endl;
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