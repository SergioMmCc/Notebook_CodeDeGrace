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

const int maxx = 1 << 30;

void solver(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n), b(m);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    for(int i = 0; i < m; i++) cin>>b[i];

    if(!k){
        cout<<sum<<endl;
        return;
    }

    vector<vector<int>> calc(n, vector<int>(m+1, maxx));
    for(int mask = 0; mask < (1 << m); mask++){
        int cnt = 0, num = maxx - 1;
        for(int bit = 0; bit < m; bit++){
            if(mask & (1 << bit)){
                cnt++;
                num &= b[bit];
            }
        }
        for(int i = 0; i < n; i++){
            int aux = num & a[i];
            calc[i][cnt] = min(calc[i][cnt], aux);
        }
    }

    vector<int> take;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            take.pb(calc[i][j-1] - calc[i][j]);
        }
    }

    sort(all(take), greater());
    for(int i = 0; i < k; i++) sum -= take[i];
    cout<<sum<<endl;
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