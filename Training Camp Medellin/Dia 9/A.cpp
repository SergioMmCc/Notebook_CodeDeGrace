#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr<< #x<<" "<<x<<endl
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    int cnt = 0;
    vi bit(n);
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            if(i == j){
                bit[i] = a[i][j];
                cnt += a[i][j];
                // cout<<" i-> "<<i<<" a[i][i] -> "<<a[i][i]<<endl;
            }
        }
    }

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 3) cout<<(cnt & 1);
        else{
            int num; cin>>num; num--;
            if(bit[num]){
                bit[num] = 0;
                cnt--;
            }
            else{
                bit[num] = 1;
                cnt++;
            }
        }
    }

    cout<<endl;
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