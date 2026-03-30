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
    int n, k; cin>>n>>k;
    vi a(n+1), reva(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        reva[a[i]] = i;
    }

    vb used(n+1);
    vi b(n+1), revb(n+1), freq(n+1);
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        if(b[i] > -1){
            used[b[i]] = 1;
            revb[b[i]] = i;
            freq[b[i]]++;
        }
    }

    int i = 1;
    for(int j = 1; j <= n; j++){
        if(b[j] != -1 && freq[b[j]] > 1){
            cout<<"NO"<<endl;
            return;
        }
        if(b[j] == -1){
            while(i <= n && used[a[i]]) i++;
            if(i > n) break;

            b[j] = a[i];
            revb[b[j]] = j;
            used[a[i]] = 1;
            i++;
        }
    }

    for(int j = 1; j <= n; j++){
        int mina = max(1, reva[j] - k + 1), minb = max(1, revb[j] - k + 1);
        int maxa = min(n, reva[j] + k - 1), maxb = min(n, revb[j] + k - 1);
        if(mina != minb || maxa != maxb){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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