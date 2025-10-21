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

void solver(){
    int n; cin>>n;
    vector<int> freq(1e6 + 1);
    for(int i = 0; i < n; i++){
        int num; cin>>num;
        freq[num]++;
    }

    queue<ll> q1, q2;
    for(int i = 1; i <= 1e6; i++){
        for(int j = 0; j < freq[i]; j++) q1.push(i);
    }

    ll ans = 0;
    while(sz(q1) + sz(q2) > 1){
        ll add = 0;
        if(!q1.empty() && (q2.empty() || q1.front() <= q2.front())){
            add += q1.front();
            q1.pop();
        }
        else{
            add += q2.front();
            q2.pop();
        }

        if(!q1.empty() && (q2.empty() || q1.front() <= q2.front())){
            add += q1.front();
            q1.pop();
        }
        else{
            add += q2.front();
            q2.pop();
        }

        ans += add;
        q2.push(add);
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