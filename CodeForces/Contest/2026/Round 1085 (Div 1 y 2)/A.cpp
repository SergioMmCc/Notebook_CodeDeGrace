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
    int n; string s; cin>>n>>s;
    int ans1 = 0, ans2 = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
    }

    for(int i = 1; i < n-1; i++){
        if(s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
    }
    for(int i = 0; i < n; i++) if(s[i] == '1') ans1++;

    bool cond = 1;
    while(cond){
        cond = 0;
        for(int i = 1; !cond && i < n-1; i++){
            if(s[i] == '1' && s[i-1] == '1' && s[i+1] == '1') s[i] = '0', cond = 1;
        }
    }
    for(int i = 0; i < n; i++) if(s[i] == '1') ans2++;

    cout<<ans2<<' '<<ans1<<endl;
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