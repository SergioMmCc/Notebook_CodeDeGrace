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

const int maxn = 2e5 + 1;

void solver(){
    int n, k; cin>>n>>k;

    vector<int> d(n+1, 1), cnt(n+1); cnt[1] = 1;
    vector<bool> leaf(n+1, 1);

    for(int i = 2; i <= n; i++){
        int p; cin>>p;
        d[i] = d[p] + 1;
        cnt[d[i]]++;
        leaf[p] = 0;
    }

    int level = n;
    for(int i = 2; i <= n; i++) if(leaf[i]) level = min(level, d[i]);

    bitset<maxn> b; b[0] = 1;
    int total = 0;
    for(int i = 1; i <= level; i++){
        b |= (b << cnt[i]);
        total += cnt[i];
    }
    for (int i = total; i < n; i++) b |= (b << 1);
    
    cout<<(b.test(k) || b.test(n - k) ? level : level - 1)<<endl;
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