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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n == 1){
        cout<<2<<endl;
        return;
    }

    // Try a0 -> L
    bool cond = a[0] == a[1] - 1 || a[0] == a[1];
    bool last = 0; // L -> 0
    int cntR = 0;
    vector<bool> pos(n);
    for(int i = 1; cond && i < n; i++){
        if(a[i] == a[i-1]) last = !last;
        else if(a[i-1] == a[i] + 1){
            if(!last) cond = 0;
        }
        else if(a[i-1] == a[i] - 1){
            if(last) cond = 0;
        }
        else cond = 0;

        cntR += last;
        pos[i] = last;
    }

    int cntL = 0;
    for(int i = 0; cond && i < n; i++){
        if(pos[i]) cntR--;
        if(a[i] != cntR + cntL + 1) cond = 0;
        if(!pos[i]) cntL++;
    }

    int ans = cond;

    // Try a0 -> R
    cond = a[0] == a[1] + 1 || a[0] == a[1];
    last = 1; // R -> 1
    cntR = 1;
    for(int i = 0; i < n; i++) pos[i] = 0;
    pos[0] = 1;
    for(int i = 1; cond && i < n; i++){
        if(a[i] == a[i-1]) last = !last;
        else if(a[i-1] == a[i] + 1){
            if(!last) cond = 0;
        }
        else if(a[i-1] == a[i] - 1){
            if(last) cond = 0;
        }
        else cond = 0;

        cntR += last;
        pos[i] = last;
    }

    cntL = 0;
    for(int i = 0; cond && i < n; i++){
        if(pos[i]) cntR--;
        if(a[i] != cntR + cntL + 1) cond = 0;
        if(!pos[i]) cntL++;
    }

    ans += cond;

    cout<<ans<<endl;
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