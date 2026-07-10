#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db(x) cerr<< #x<<" "<<x<<endl
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vi a(n+1), freq(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(freq[i] >= 1) cnt++;
    }

    set<int> to, from;
    for(int i = 1; i <= n; i++){
        to.insert(i);
        from.insert(i);
    }

    vi ans(n+1);
    int happy = 0;

    if(cnt == n-1){
        for(int i = 1; i <= n; i++){
            if(to.find(a[i]) != to.end()){
                // cout<<a[i]<<' '<<i<<endl;
                happy++;
                ans[i] = a[i];
                to.erase(a[i]);
                from.erase(i);
            }
        }
        // cout<<"sizes "<<sz(from)<<' '<<sz(to)<<endl;
        // assert(sz(to) == 1 && sz(from) == 1);
        if(*to.begin() != *from.begin()){
            ans[*from.begin()] = *to.begin();

            cout<<happy<<endl;
            for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
            cout<<endl;
            return;
        }

        for(int i = 1; i <= n; i++){
            to.insert(i);
            from.insert(i);
            ans[i] = 0;
        }

        happy = 0;
        for(int i = n; i > 0; i--){
            if(to.find(a[i]) != to.end()){
                happy++;
                ans[i] = a[i];
                to.erase(a[i]);
                from.erase(i);
            }
        }

        ans[*from.begin()] = *to.begin();
        cout<<happy<<endl;
        for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
        cout<<endl;
        return;
    }


    for(int i = 1; i <= n; i++){
        if(to.find(a[i]) != to.end()){
            happy++;
            ans[i] = a[i];
            to.erase(a[i]);
            from.erase(i);
        }
    }

    vi x;
    for(int aux : from) x.pb(aux);
    vi y;
    for(int aux : to) y.pb(aux);

    int i = 0;
    for(i = 0; i < sz(x) - 1; i++){
        if(x[i] == y[i]){
            ans[x[i]] = y[i+1];
            ans[x[i+1]] = y[i];
            i++;
        }
        else ans[x[i]] = y[i];
    }
    // db(sz(x));
    if(sz(x) && i < sz(x)){
        assert(i);
        if(x[i] == y[i]){
            ans[x[i]] = ans[x[i-1]];
            ans[x[i-1]] = y[i];
        }
        else ans[x[i]] = y[i];
    }

    cout<<happy<<endl;
    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
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