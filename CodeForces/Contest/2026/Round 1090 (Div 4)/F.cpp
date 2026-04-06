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
    int x, y; cin>>x>>y;
    if(y < x){
        cout<<"NO"<<endl;
        return;
    }
    if(!x && (y & 1) == 0){
        cout<<"NO"<<endl;
        return;
    }

    int n = x + y;

    int idx = 1;
    int st = n & 1;
    vii ans;

    while(x){
        ans.pb({idx, idx+1});
        if(st){
            y--;
            st = 0;
        }
        else{
            x--;
            st = 1;
        }
        idx++;
    }

    for(int j = idx+1; j <= n; j++) ans.pb({idx, j});

    cout<<"YES"<<endl;
    for(pii x : ans) cout<<x.fi<<' '<<x.se<<endl;
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