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
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, m; cin>>n>>m;
    vector<vb> a(n, vb(m));
    vi sc(m);
    ll cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int aux; cin>>aux;
            if(aux){
                cnt1++;
                sc[j]++;
            }
            a[i][j] = aux;
        }
    }

    cout<<(cnt1 / 2LL) * ((cnt1 + 1LL) / 2LL)<<endl;  

    string ans = "";
    int tope = (int)cnt1 / 2;
    int cur = 0;
    bool cond = 0;
    int i = 0, j = 0;
    for(; j < m; j++){
        if(cur <= tope && cur + sc[j] > tope){
            cond = 1;

            int need = tope - cur;
            int aux = 0;
            for(; sc[j] - aux > need && i < n; i++){
                ans += 'D';
                if(a[i][j]) aux++;
            }

            ans += 'R';
            for(; i < n; i++) ans += 'D';
        }

        else ans += 'R';

        cur += sc[j];
    }
    for(; i < n; i++) ans += 'D';

    // for(int i = 0; i < sz(ans); i++) cout<<"i -> "<<i<<" ans -> "<<ans[i]<<endl;
    assert(sz(ans) == n + m);
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