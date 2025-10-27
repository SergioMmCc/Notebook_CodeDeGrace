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
    int n, k; cin>>n>>k;
    vector<int> a(n);
    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++){
        cin>>a[i];

        for(int j = 1; j * j < a[i]; j++){
            if(a[i] % j == 0){
                if(a[i] < 4*j) cnt[j]++;
                int div = a[i] / j;
                if(a[i] < 4*div) cnt[div]++;
            }
        }

        int r = sqrt(a[i]);
        if(r * r == a[i] && a[i] < 4*r) cnt[r]++;
    }

    sort(all(a));


    for(int i = n; i > 0; i--){
        int s = 4*i;
        auto it = lb(all(a), s);
        int add = distance(it, a.end());
        // cout<<"i -> "<<i<<" add -> "<<add<<" cnt -> "<<cnt[i]<<endl;

        if(cnt[i] + add >= n - k){
            cout<<i<<endl;
            return;
        }
    }

    cout<<1<<endl;
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