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

const ll mod = 1e9 + 7;

vector<ll> pot2(301);
void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 301; i++) pot2[i] = (pot2[i-1] * 2LL) % mod;
}

void solver(){
    int n; cin>>n;
    ll ans = pot2[n];
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int add1 = 0;
    for(int i = 0; i < n - 2; i++){
        bool cond1 = 1;
        int add2 = 0;
        for(int j = i + 1; j < n - 1; j++){
            if(a[j] >= a[i]){
                add2++;
                continue;
            }

            bool cond2 = 1;
            int add3 = 0;
            for(int k = j + 1; k < n; k++){
                if(a[k] >= a[j]){
                    add3++;
                    continue;
                }

                cout<<"i -> "<<i<<" j -> "<<j<<" k -> "<<k<<" ans -> "<<ans<<endl;
                ans = (ans - pot2[add1 + add2 + add3 + n - k - 1] + mod) % mod;
                cond1 = cond2 = 0;
            }

            add2 += cond2;
        }

        add1 += cond1;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}