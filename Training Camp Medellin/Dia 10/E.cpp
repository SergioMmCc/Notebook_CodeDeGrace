#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr<< #x<<" "<<x<<endl
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
    int n; cin>>n;
    vb a(n);
    string s; cin>>s; 
    for(int i = 0; i < n; i++) a[i] = s[i] == 'L';

    if(n <= 2){
        cout<<0<<endl;
        return;
    }

    bool cond = 1;
    for(int i = 1; cond && i < n; i++) cond = a[i] == a[i-1];

    if(cond){
        cout<<(n + 2)/3<<endl;
        return;
    }


    int idx = 0, jdx = n, len = 1;
    if(a[0] == a[n-1]){
        while(a[idx + 1] == a[idx]){
            idx++;
            len++;
        }
        while(a[jdx-1] == a[0]){
            jdx--;
            len++;
        }
        idx++;
    }

    int ans = len / 3;

    len = 0;
    for(int i = idx; i < jdx;){
        bool w = a[i];
        len = 0;
        while(i < n && a[i] == w){
            // cout<<"i -> "<<i<<" w -> "<<w<<endl;
            len++;
            i++;
        }

        ans += len / 3;
        len = 0;
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