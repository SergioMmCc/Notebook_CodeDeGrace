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

const int maxn = 2e5 + 1;

void solver(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> last;
    vector<int> add;
    for(int i = 1; i*i <= a[0]; i++){
        if(i*i == a[0]){
            last.pb(i);
            break;
        }
        if(a[0] % i == 0){
            last.pb(i);
            add.pb(a[0] / i);
        }
    }

    for(int j = sz(add) - 1; j >= 0; j--) last.pb(add[j]);

    cout<<0;
    int maxi = 0;
    vector<int> cnt(maxn);
    for(int j = 1; j < n; j++){
        int num = a[j];
        vector<int> next;
        vector<int> r;
        for(int i = 1; i*i <= num; i++){
            if(i*i == num){
                next.pb(i);
                break;
            }
            if(a[j] % i == 0){
                next.pb(i);
                r.pb(num / i);
            }
        }

        for(int k = sz(r) - 1; k >= 0; k--) next.pb(r[k]);

        int x = 0, y = 0;
        vector<int> copy;
        while(x < sz(last) || y < sz(next)){
            if((x < sz(last) && y < sz(next)) && last[x] == next[y]){
                copy.pb(last[x]);
                x++;
                y++;
            }
            else if(x < sz(last) && (y >= sz(next) || last[x] < next[y])){
                cnt[last[x]] = j;
                maxi = max(maxi, j);
                x++;
            }
            else{
                cnt[next[y]]++;
                maxi = max(maxi, cnt[next[y]]);
                y++;
            }
        }
        cout<<' '<<maxi;

        last = copy;
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