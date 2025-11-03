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

const int inf = 1e9;

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = s[i] - 'A';

    vector<int> mod(n);
    for(int i = 0; i < n; i++){
        mod[i] = a[i];
        for(int j = 0; j < n; j++){
            if(a[j] > mod[i]) a[j]--;
        }
    }
    mod.pb(0);

    // for(int i = 0; i < n; i++) cout<<mod[i]<<' '; cout<<endl;

    vector<int> prod = {1, 1, 2, 3, 2, 5, 1, 7, 2, 3, 1, 11, 1, 13, 1, 1, 2, 17, 1, 19, 1};

    reverse(mod.begin(), mod.end());
    int ans = 0;
    int sum = 1;
    for(int i = 2; i <= n; i++){;
        while(ans < inf && ans % i != mod[i]){
            ans += sum;
        }

        if(ans >= inf){
            cout<<"NO"<<endl;
            return;
        }

        sum *= prod[i];
    }

    cout<<"YES"<<endl<<ans<<endl;
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