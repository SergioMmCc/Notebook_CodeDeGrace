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
    auto it = a.end(); it--;
    if(2 * (*it) >= sum){
        cout<<"IMPOSSIBLE TO WIN"<<endl;
        return;
    }
    it--;
    ll cnt = *it;

    int ans = 0;
    ll use = 0;
    while(!a.empty() && 2*cnt <= sum){
        ll less = *a.begin();
        if(less == cnt){
            cout<<"IMPOSSIBLE TO WIN"<<endl;
            return;
        }

        ll add = use;
        while(!a.empty() && *a.begin() == less){
            add += less;
            a.erase(a.begin());
        }

        if(2*(cnt + add) > sum){
            cout<<ans+1<<endl;
            return;
        }

        ll idx = 0;
        ll maxx = 0;
        for(ll x : a){
            ll res = idx * (x - maxx);
            idx++;
            if(add < res){
                idx--;
                assert(idx);
                maxx += add / idx;
                add -= idx*(add/idx);
                break;
            }
            else{
                if(x == cnt){
                    res = (idx-1) * (x - 1 - maxx);
                    add -= res;
                    maxx = x-1;
                    idx--;
                    break;
                }
                maxx = x;
                add -= res;
            }
        }

        if(2*(cnt + add + idx*maxx) > sum){
            cout<<ans+2<<endl;
            return;
        }
        assert(idx <= sz(a));
        for(int i = 1; i <= idx; i++) a.erase(a.begin());
        for(int i = 1; i <= idx; i++) a.insert(maxx);
        use = add;

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