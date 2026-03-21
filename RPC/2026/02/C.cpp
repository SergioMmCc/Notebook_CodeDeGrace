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

int calc(int r, vi& u, vi& d){
    int ans = d[r-1];
    for(int i = 0; i < r; i++){
        ans = min(ans, u[i] + d[r-1] - d[i]);
    }

    return ans;
}

void solver(){
    int r, c; cin>>r>>c;
    string s; cin>>s;
    int n = r+c-2;

    int ans = 0;
    int x = 0, y = 0;
    vi lu(r), ld(r), ru(r), rd(r);
    for(int i = 0; i < n; i++){
        if(s[i] == 'D') y++;
        else x++;

        if(i && s[i] != s[i-1]) ans++;
        if(i && s[i] == s[i-1]){
            if(s[i] == 'R' && y) rd[y-1]++;
            else if(s[i] == 'D') ld[y]++;
        }
        if(i < n-1 && s[i] == s[i+1]){
            if(s[i] == 'R' && y < r-1) lu[y+1]++;
            else if(s[i] == 'D') ru[y-1]++;
        }
    }
    for(int i = 1; i < r; i++){
        lu[i] += lu[i-1];
        ld[i] += ld[i-1];
        ru[i] += ru[i-1];
        rd[i] += rd[i-1];
    }
    // for(int i = 0; i < r; i++) cout<<lu[i]<<' '<<ld[i]<<' '<<ru[i]<<' '<<rd[i]<<endl;
    // cout<<"ans -> "<<ans<<endl;

    cout<<ans + calc(r, lu, ld) + calc(r, ru, rd)<<endl;
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