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

vector<int> getSegs(int l, int r){
    vector<int> ans;
    while(l < r){
        int bit = min(__builtin_ctz(l), 31 - __builtin_clz(r - l));
        ans.pb(1 << bit);
        l += (1 << bit);
    }

    sort(all(ans));
    return ans;
}

void solver(){
    int l1, r1, l2, r2; cin>>l1>>r1>>l2>>r2;
    vector<int> a = getSegs(l1, r1), b = getSegs(l2, r2);

    int lena = r1 - l1, lenb = r2 - l2;
    int ans = 0;
    int i = 0, j = 0;
    while(i < sz(a) || j < sz(b)){
        if(j >= sz(b) || (i < sz(a) && a[i] <= b[j])){
            ans += lenb / a[i];
            lena -= a[i];
            i++;
        }
        else{
            ans += lena / b[j];
            lenb -= b[j];
            j++;
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