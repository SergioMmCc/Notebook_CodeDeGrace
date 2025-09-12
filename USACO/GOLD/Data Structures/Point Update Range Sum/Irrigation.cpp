#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
// #define int long long
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ordered_set = 
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    ll n; int m, q; cin>>n>>m>>q;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        int idx; cin>>idx;
        freq[idx]++;
    }

    // Inicio de cada indice
    ll mini = n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= m; i++){
        int r = 0;
        if(freq.find(i) != freq.end()) r = freq[i];
        mini = min(mini, (ll)r);
        pq.push({r, i});
    }

    priority_queue<pli, vector<pli>, greater<pli>> queries;
    for(int i = 0; i < q; i++){
        ll idx; cin>>idx;
        queries.push({idx, i});
    }

    vector<int> ans(q);
    ordered_set cities;
    while(!queries.empty() && !pq.empty()){
        while(!pq.empty() && mini == pq.top().fi){
            cities.insert(pq.top().se);
            pq.pop();
        }
        mini++;
        
        ll len = (ll)cities.sz;
        while(!queries.empty() && queries.top().fi <= n + len){
            ll when = queries.top().fi; int idx = queries.top().se;
            queries.pop();

            ll s = when - n - 1;
            auto it = cities.find_by_order(s);
            ans[idx] = *it;
        }

        n += len;
    }

    while(!queries.empty()){
        ll when = queries.top().fi, idx = queries.top().se;
        queries.pop();
        ll s = (when - n) % (ll)m;
        if(!s) s = (ll)m;
        s--;
        auto it = cities.find_by_order(s);
        ans[idx] = *it;
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}