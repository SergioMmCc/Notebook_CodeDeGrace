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
    int n; cin>>n;
    multiset<ll> a;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll num; cin>>num;
        a.insert(num);
        sum += num;
    }
    auto it = a.end(); it--; it--;
    ll cnt = *it;

    int ans = 0;
    while(!a.empty() && 2*cnt <= sum){
        ll less = *a.begin();
        if(less == cnt){
            cout<<"IMPOSSIBLE TO WIN"<<endl;
            return;
        }

        ll add = 0;
        while(!a.empty() && *a.begin() == less){
            add += less;
            a.erase(a.begin());
        }

        auto aux = a.find(cnt);
        a.erase(aux);
        cnt += add;
        a.insert(cnt);
        ans++;
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