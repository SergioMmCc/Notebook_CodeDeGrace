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
    int n; cin>>n;
    vl a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll r = sqrt((ll)n);
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        ll y = a[i];
        if(y >= (ll)n) continue;
        if(y <= r){
            for(ll x = 1; x <= r ; x++){
                ll l = i - x*a[i];
                ll r = i + x*a[i];
                if(l < 0 && r >= n) break;

                if(l >= 0 && a[l] == x) cnt1++;
                if(r < n && a[r] == x) cnt1++;
            }
        }
        else{
            for(ll x = 1; x <= r ; x++){
                ll l = i - x*a[i];
                ll r = i + x*a[i];
                if(l < 0 && r >= n) break;

                if(l >= 0 && a[l] == x) cnt2++;
                if(r < n && a[r] == x) cnt2++;
            }
        }
    }

    cout<<cnt1 / 2 + cnt2<<endl;
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