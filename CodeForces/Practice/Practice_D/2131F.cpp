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
    string a, b; cin>>a>>b;
    vector<ll> cnta0(n+1), cnta1(n+1), cntb0(n+1), cntb1(n+1), difa(n+1), difb(n+1);
    vector<ll> w(2*n + 1), add0(2*n + 1), add1(2*n + 1);
    for(int i = 0; i < n; i++){
        cnta0[i+1] = cnta0[i];
        cnta1[i+1] = cnta1[i];
        cntb0[i+1] = cntb0[i];
        cntb1[i+1] = cntb1[i];
        if(a[i] == '0') cnta0[i+1]++;
        else cnta1[i+1]++;
        if(b[i] == '0') cntb0[i+1]++;
        else cntb1[i+1]++;

        difa[i+1] = cnta1[i+1] - cnta0[i+1];
        difb[i+1] = cntb1[i+1] - cntb0[i+1];

        w[difa[i+1] + n]++;
        add0[difa[i+1] + n] += cnta0[i+1];
        add1[difa[i+1] + n] += cnta1[i+1];
    }

    for(int i = 1; i <= 2*n; i++){
        w[i] += w[i-1];
        add0[i] += add0[i-1];
        add1[i] += add1[i-1];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(n - difb[i] - 1 < 0){
            ans += add0[2*n] + cntb0[i] * w[2*n];
        }
        else{
            ans += add0[2*n] - add0[n - difb[i] - 1] + cntb0[i] * (w[2*n] - w[n - difb[i] - 1]);
            ans += add1[n - difb[i] - 1] + cntb1[i] * w[n - difb[i] - 1];
        }
    }

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