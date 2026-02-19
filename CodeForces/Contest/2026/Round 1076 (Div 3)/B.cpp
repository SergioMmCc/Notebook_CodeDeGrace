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
    vi p(n);
    int maxx = n;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        cin>>p[i];
        if(l == -1 && p[i] == maxx) maxx--;
        else if(l == -1) l = i;

        else if(p[i] == maxx) r = i;
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        if(i >= l && i <= r) cout<<p[r + l - i];
        else cout<<p[i];
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