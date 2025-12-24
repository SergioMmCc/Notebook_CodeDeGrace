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
    int cnti = 0;
    vector<ll> par;
    ll imp = 0;
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        if(num % 2){
            imp = max(imp, num);
            cnti++;
        }
        else par.pb(num);
    }

    if(!cnti){
        for(int i = 0; i < n; i++) cout<<0<<' '; cout<<endl;
        return;
    }

    cnti--;
    sort(all(par));
    reverse(all(par));
    cout<<imp;
    ll prev, bigg;
    ll sum = imp;
    if(sz(par) == 0) prev = 0, bigg = imp;
    else if(sz(par) == 1) prev = imp;
    for(int i = 0; i < sz(par); i++){
        sum += par[i];
        cout<<' '<<sum;
        if(i + 1 == sz(par)) bigg = sum;
        else if(i + 2 == sz(par)) prev = sum;
    }

    while(cnti >= 2){
        cnti -= 2;
        cout<<' '<<prev<<' '<<bigg;
    }
    if(cnti == 1) cout<<' '<<0;
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