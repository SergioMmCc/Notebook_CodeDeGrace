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
    string s; cin>>s;
    bool cond = 0;
    for(int i = 0; !cond && i < n; i++) if(s[i] == 'B') cond = 1;
    while(q--){
        int x; cin>>x;
        if(!cond){
            cout<<x<<endl;
            continue;
        }
        int idx = 0;
        while(x > 0){
            if(s[idx % n] == 'A') x--;
            else x >>= 1;
            idx++;
        }

        cout<<idx<<endl;
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