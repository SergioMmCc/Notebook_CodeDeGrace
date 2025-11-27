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
    int p1, pn;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] == 1) p1 = i+1;
        if(a[i] == n) pn = i+1;
    }

    string s; cin>>s;
    if(s[0] == '1' || s[n-1] == '1' || s[p1-1] == '1' || s[pn-1] == '1'){
        cout<<-1<<endl;
        return;
    }

    cout<<5<<endl;
    if(p1 > pn) swap(p1, pn);
    cout<<1<<' '<<p1<<endl;
    cout<<1<<' '<<pn<<endl;
    cout<<p1<<' '<<n<<endl;
    cout<<pn<<' '<<n<<endl;
    cout<<p1<<' '<<pn<<endl;
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