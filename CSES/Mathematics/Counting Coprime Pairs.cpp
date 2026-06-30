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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ll gauss(ll n){
    return (n * (n+1)) / 2;
}

void solver(){
    int n; cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        int aux = 1;
        for(int j = 2; j * j <= a[i]; j++){
            if(a[i] % j == 0) aux *= j;
            while(a[i] % j == 0) a[i] /= j;
        }
        a[i] *= aux;
    }

    vi div(1e6 + 1);

    for(int i = 0; i < n; i++){
        for(int j = 1; j * j < a[i]; j++){
            if(a[i] % j == 0){
                div[j]++;
                div[a[i] / j]++;
            }
        }
        int r = sqrt(a[i]);
        if(r*r == a[i]) div[r]++;
    }

    ll ans = gauss(n-1);
    for(int i = 2; i <= 1e6; i++){
        if(!div[i]) continue;

        int cnt = 0, aux = i;
        for(int j = 2; j*j <= aux; j++){
            if(aux % j == 0) cnt++;
            while(aux % j == 0) aux /= j;
        }
        if(aux > 1) cnt++;

        if(cnt & 1) ans -= gauss((ll)div[i] - 1);
        else ans += gauss((ll)div[i] - 1);
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