#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vector<int> a(n+2);
    for(int i = n; i >= 0; i--) cin>>a[i];

    n++;

    vector<int> comp(n+1); comp[0] = 1;
    int ans = 0;
    while(a != comp){
        ans++;
        if(!a[0]){
            for(int i = 0; i < n; i++) a[i] = a[i+1];
            a[n] = 0;
            continue;
        }
        
        vector<int> b(n+1);
        for(int i = n; i > 0; i--){
            b[i] = a[i] ^ a[i-1];
        }
        b[0] = 0;
        a = b;
    }

    cout<<ans<<endl;
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