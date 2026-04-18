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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    vi d(n);
    for(int i = 0; i < n; i++) cin>>d[i];

    vb used(n+1, 1);
    for(int i = 0; i < n; i++){
        int num = a[i];
        used[num] = 0;
        int cnt = 0;
        for(int j = n; cnt < d[i] && j > num; j--) if(used[j]) cnt++;
        if(cnt < d[i]){
            cout<<-1<<endl;
            return;
        }
    }

    vi ans(n);
    priority_queue<int, vi, greater<int>> pq;
    vb mark(n);
    for(int i = 0; i < n; i++){
        if(!d[i]){
            pq.push(i);
            mark[i] = 1;
        }
    }
    
    int save = n;
    while(!pq.empty()){
        int idx = pq.top(); pq.pop();
        int num = a[idx];
        ans[idx] = save;
        save--;

        for(int i = idx-1; i >= 0; i--){
            if(!mark[i] && a[i] < num){
                d[i]--;
                if(!d[i]){
                    mark[i] = 1;
                    pq.push(i);
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     if(i) cout<<' ';
    //     cout<<menor[a[i]];
    // }
    // cout<<endl;
    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
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