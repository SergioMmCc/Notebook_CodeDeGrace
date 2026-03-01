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
    int n; string s; cin>>n>>s;
    int cnt0 = 0, cnt1 = 0;
    vi a0, a1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            cnt0++;
            a0.pb(i+1);
        }
        else{
            cnt1++;
            a1.pb(i+1);
        }
    }

    if(n % 2 && cnt1 % 2){
        cout<<-1<<endl;
        return;
    }

    if(n % 2){
        cout<<min(cnt1, cnt0)<<endl;
        for(int i = 0; i < min(cnt1, cnt0); i++){
            if(cnt1 < cnt0) cout<<a1[i]<<' ';
            else cout<<a0[i]<<' ';
        }
        if(min(cnt0, cnt1)) cout<<endl;
    }

    else{
        if(cnt1 % 2){
            cout<<cnt0<<endl;
            for(int i = 0; i < cnt0; i++) cout<<a0[i]<<' ';
            if(cnt0) cout<<endl;
        }
        else{
            cout<<cnt1<<endl;
            for(int i = 0; i < cnt1; i++) cout<<a1[i]<<' ';
            if(cnt1) cout<<endl;
        }
    }
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