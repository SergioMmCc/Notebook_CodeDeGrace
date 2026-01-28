#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define endl '\n'
using ll = long long;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    ordered_set use;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        use.insert(i);
        cin>>a[i];
        pq.push({a[i], i});
    }

    // while(!pq.empty()){
    //     cout<<"num -> "<<pq.top().fi<<" index -> "<<pq.top().se<<endl;
    //     pq.pop();
    // }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        use.erase(i);
        while(!pq.empty() && pq.top().fi < i){
            int index = pq.top().se;
            use.erase(index);
            // cout<<"erase -> "<<index<<endl;
            pq.pop();
        }

        auto it = use.upper_bound(a[i]);
        if(it == use.begin()) continue;
        --it;
        
        ans += use.order_of_key(a[i] + 1);
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}