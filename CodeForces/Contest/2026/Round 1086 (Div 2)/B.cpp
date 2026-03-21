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
    int n, k, p, m; cin>>n>>k>>p>>m;
    set<pii> w;
    queue<int> q;
    vi a(n+1);
    bool is = 0;
    int idx = p;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(i <= k){
            w.insert({a[i], i});
            if(i == p) is = 1;
        }
        else{
            q.push(i);
        }
    }

    if(k == n){
        cout<<m / a[p]<<endl;
        return;
    }

    int ans = 0;
    while(m >= 0){
        if(is){
            if(m >= a[p]){
                m -= a[p];
                w.erase({a[p], p});
                q.push(p);
                idx = n;
                ans++;
                is = 0;
            }
            else break;
        }
        else{
            idx--;
            if(idx == k) is = 1;
            auto it = w.begin();
            if(m >= (*it).fi){
                m -= (*it).fi;
                q.push((*it).se);
                w.erase(it);
            }
            else break;
        }

        w.insert({a[q.front()], q.front()});
        q.pop();
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