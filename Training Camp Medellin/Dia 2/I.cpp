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

void solver(){
    int n, m; cin>>n>>m;
    int l = m+1, r = 0, u = n+1, d = 0;
    vs maze(n+1);
    vector<vi> a(n+1, vi(m+1)), s(n+1, vi(m+1));
    for(int i = 1; i <= n; i++){
        cin>>maze[i];
        maze[i] += ' ';
        for(int j = m; j > 0; j--) maze[i][j] = maze[i][j-1];
        for(int j = 1; j <= m; j++){
            if(maze[i][j] == 'B'){
                a[i][j] = 1;
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    }

    if(!r){
        cout<<1<<endl;
        return;
    }
    // cout<<u<<' '<<d<<' '<<l<<' '<<r<<endl;
    int leny = d - u + 1, lenx = r - l + 1;
    int maxi = max(leny, lenx);
    if(maxi > n || maxi > m){
        cout<<-1<<endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = max(1, d - maxi + 1); i <= u && i + maxi <= n+1; i++){
        for(int j = max(1, r - maxi + 1); j <= l && j + maxi <= m+1; j++){
            int limi = i + maxi - 1, limj = j + maxi - 1;
            ans = max(ans, s[limi][limj] - s[i-1][limj] - s[limi][j-1] + s[i-1][j-1]);
        }
    }

    ans = maxi * maxi - ans;
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