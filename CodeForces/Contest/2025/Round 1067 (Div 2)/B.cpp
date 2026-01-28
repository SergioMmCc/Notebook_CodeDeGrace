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
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vi freq(2*n+1);
    int maxx = 0;
    for(int i = 0; i < 2*n; i++){
        int num; cin>>num;
        maxx = max(num, maxx);
        freq[num]++;
    }

    int ans = 0, cnt = 0;
    bool imp = 0;
    for(int i = 1; i <= 2*n; i++){
        if(!freq[i]) continue;
        if(freq[i] & 1){
            ans++;
            imp = 1;
        }
        else{
            if(freq[i] % 4) ans += 2;
            else cnt++;
        }
    }

    ans += (cnt / 2) * 4;
    if((cnt & 1) && imp) ans += 2;
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