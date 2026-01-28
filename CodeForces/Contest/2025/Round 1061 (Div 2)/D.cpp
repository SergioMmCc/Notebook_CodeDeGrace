#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

int query(int i, int x){
    cout<<"? "<<i<<' '<<x<<endl;
    int ans; cin>>ans;
    return ans;
}

void res(int n){
    cout<<"! "<<n<<endl;
}

void solver(){
    int n; cin>>n;
    int bits = 0;
    int aux = n;
    while(aux > 0){
        bits++;
        aux /= 2;
    }

    int ans = 0;
    vector<int> pos(n);
    vector<int> test(n);
    for(int i = 0; i < n; i++){
        pos[i] = i+1;
        test[i] = i+1;
    }
    test.pop_back();

    for(int bit = 0; bit < bits; bit++){
        vector<int> c1, c2;
        for(int p : pos){
            if(p & (1 << bit)) c1.pb(p);
            else c2.pb(p);
        }

        vector<int> b1, b2;
        for(int t : test){
            int b = query(t, 1 << bit);
            if(b) b1.pb(t);
            else b2.pb(t);
        }

        // cout<<"bit -> "<<bit;
        // cout<<endl<<"c1 -> "<<endl;
        // for(int c : c1) cout<<c<<' ';
        // cout<<endl<<"c2 -> "<<endl;
        // for(int c : c2) cout<<c<<' ';
        // cout<<endl<<"b1 -> "<<endl;
        // for(int b : b1) cout<<b<<' ';
        // cout<<endl<<"b2 -> "<<endl;
        // for(int b : b2) cout<<b<<' ';

        if(sz(b1) < sz(c1)){ // En ans, ese bit es 1
            // cout<<"bit 1"<<endl;
            ans += 1 << bit;
            pos = c1;
            test = b1;
        }

        else{
            pos = c2;
            test = b2;
        }
    }

    res(ans);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}