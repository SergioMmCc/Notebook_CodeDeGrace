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
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vl win(n+1);
    for(int i = 1; i <= n; i++){
        cin>>win[i];
    }

    vd pm(n+1), pe(n+1);
    for(int i = 1; i <= n; i++){
        cin>>pm[i];
    }

    vector<vd> sm(n+2, vd(n+2, 1.0));
    for(int i = 1; i <= n; i++){
        sm[i][i] = pm[i];
        for(int j = i+1; j <= n; j++){
            sm[i][j] = sm[i][j-1] * pm[j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        cin>>pe[i];
    }

    if(n == 1){
        cout<<(ld)win[1] * pe[1]<<endl;
        return;
    }

    ld ans = 0.0;

    ld aux1 = 1.0;
    for(int i = 1; i < n; i++){
        ld aux2 = 1.0;
        for(int j = i+1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                ld aux = (ld)win[k] * aux1 * pe[i];
                if(j <= k) aux *= aux2 * pe[j] * sm[j+1][k];
                else aux *= sm[i+1][k];
                ans = max(ans, aux);
                // cout<<"i -> "<<i<<" j -> "<<j<<" k -> "<<k<<" ans -> "<<ans<<endl;
            }

            aux2 *= pm[j];
        }

        aux1 *= pm[i];
    }

    cout<<fixed<<setprecision(7)<<ans<<endl;
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