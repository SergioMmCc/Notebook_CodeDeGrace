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
    int n; cin>>n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(all(a));
    for(int i = 0; i < n; i++) cin>>b[i];
    sort(all(b));

    int lim = n - (n/4);
    int s1 = 0, s2 = 0;
    pqueue<int, vi, greater<int>> minpq; minpq.push(100);
    for(int i = 0; i < lim; i++){
        minpq.push(a.back());
        s1 += a.back(); a.pop_back();
        s2 += b.back(); b.pop_back();
    }
    pqueue<int> pq; pq.push(0);
    while(!b.empty()){
        pq.push(b.back());
        b.pop_back();
    }


    int ans = 0;
    while(s1 < s2){
        // cout<<s1<<' '<<s2<<' '<<n<<endl;
        n++;
        ans++;
        if(n % 4 == 0){
            s1 += 100;
            s1 -= minpq.top(); minpq.pop(); minpq.push(100);
        }
        else{
            // cout<<"here s1 -> "<<s1;
            s1 += 100;
            // cout<<" s1N -> "<<s1<<" s2 -> "<<s2;
            s2 += pq.top(); pq.pop();
            // cout<<" s2N -> "<<s2<<endl;
            pq.push(0);
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