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
    int n, m, l; cin>>n>>m>>l;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    m = min(m, n+1);
    int idx = 0;
    vi b(m+1);
    for(int i = 1; i <= l; i++){
        int mini = l;
        for(int j = m; j >= 1; j--){
            mini = min(mini, b[j]);
        }
        
        for(int j = m; j > 0; j--){
            if(b[j] == mini){
                b[j]++;
                break;
            }
        }
        if(idx < n && i == a[idx]){
            sort(all(b));
            b[m] = 0;
            if(n - idx == m-1){
                m--;
                b.pop_back();
            }

            idx++;
        }
    }

    cout<<b[1]<<endl;
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