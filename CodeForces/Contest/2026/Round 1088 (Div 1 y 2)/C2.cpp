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
    vb mid(n+1);
    for(int i = 1; i <= k; i++) mid[i] = i <= k && k+i > n;
    vi a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        b[i] = max(b[i], 0);
    }

    if(k == 1){
        for(int i = 1; i <= n; i++){

        }
    }

    vi val(k);
    for(int i = 0; i < k; i++){
        int j = i;
        if(!j) j = k;

        bool cond = 1;
        for(int idx = j; cond && idx <= n; idx += k){
            if(val[i] && a[idx] != val[i]) cond = 0;
            else val[i] = a[idx];
        }

        int aux = 0;
        if(cond){
            for(int idx = j; idx <= n; idx += k){
                if(aux && b[idx] && aux != b[idx]){
                    cout<<"NO"<<endl;
                    return;
                }
                if(!aux) aux = b[idx];
            }
            for(int idx = j; idx <= n; idx += k) b[idx] = aux;
        }
        else{
            for(int idx = j; idx <= n; idx += k){
                if(a[idx] != b[idx] && b[idx]){
                    cout<<"NO"<<endl;
                    return;
                }
                b[idx] = a[idx];
            }
        }
    }

    vi freqa(n+1), freqb(n+1);
    for(int i = 1; i <= k; i++){
        freqa[a[i]]++;
        freqb[b[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(freqb[i] > freqa[i]){
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