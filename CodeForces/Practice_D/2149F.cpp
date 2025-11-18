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

bool check(ll k, ll h, ll d){
    ll len = d / (k + 1);
    ll plus = d % (k + 1);
    ll res = k + 1 - plus;
    ll cost = h + k - plus * (((len + 1) * (len + 2)) / 2) - res * (((len + 1) * (len)) / 2);
    return cost > 0;
}

void solver(){
    ll h, d; cin>>h>>d;

    ll i = 0, j = d, ans = d;
    while(i <= j){
        ll m = (i + j) / 2;
        bool cond = check(m, h, d);
        if(cond){
            j = m - 1;
            ans = m;
        }
        else i = m + 1;
    }

    cout<<d + ans<<endl;
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