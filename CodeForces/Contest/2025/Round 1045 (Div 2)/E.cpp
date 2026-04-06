#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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

int askT(int x){
    cout<<"throw "<<x<<endl;
    int r; cin>>r;
    return r;
}

void askS(int x){
    cout<<"swap "<<x<<endl;
}

void ans(vi& a){
    cout<<'!';
    for(int i = 1; i < sz(a); i++){
        cout<<' '<<a[i];
    }
    cout<<endl;
}

void solver(){
    int n; cin>>n;
    vi a(n+1), cnt(n+1);

    cnt[n] = 1;
    cnt[n-1] = askT(n-1);
    a[n-1] = cnt[n-1] == 2 ? 1 : 2;

    stack<int> st;
    for(int i = n-2; i > 0; i--){
        if(cnt[i+1] == cnt[i+2]){
            st.push(i);
            cnt[i] = cnt[i+1] + 1;
            continue;
        }

        cnt[i] = askT(i);
        a[i] = cnt[i] == cnt[i+1] + 1 ? 1 : 2;
    }

    while(!st.empty()){
        int i = st.top(); st.pop();
        askS(i);
        cnt[i] = askT(i+1);
        a[i] = cnt[i] == cnt[i+1] ? 2 : 1;
    }

    askS(n-1);
    cnt[n] = askT(n-1);
    a[n] = cnt[n] == 1 ? 2 : 1;

    ans(a);
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}