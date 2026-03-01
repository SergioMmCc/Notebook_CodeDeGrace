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
    vector<vi> a(n);
    vector<set<int>> reps(n);
    for(int i = 0; i < n; i++){
        int l; cin>>l;
        vi aux(l);
        for(int j = 0; j < l; j++){
            cin>>aux[j];
        }

        // Para que ningun array tenga repeticiones
        reverse(all(aux));
        // for(int j = 0; j < l; j++) cout<<aux[j]<<' '; cout<<endl;

        for(int j = 0; j < l; j++){
            // cout<<"auxj -> "<<aux[j]<<endl;
            // for(int x : reps[i]) cout<<"x -> "<<x<<' ';
            if(reps[i].find(aux[j]) == reps[i].end()){
                // cout<<"here"<<endl;
                a[i].pb(aux[j]);
                reps[i].insert(aux[j]);
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < sz(a[i]); j++){
    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    vi q;
    while(!a.empty()){
        sort(all(a), greater());
        set<int> del;
        int len = sz(a) - 1;
        for(int x : a[len]){
            q.pb(x);
            del.insert(x);
        }

        // Eliminar a[len]
        a.pop_back();

        if(del.empty()) continue;

        // Eliminar los procesados
        for(int i = 0; i < len; i++){
            vi copy;
            for(int c : a[i]) if(del.find(c) == del.end()) copy.pb(c);

            a[i] = copy;
        }
    }

    for(int i = 0; i < sz(q); i++){
        if(i) cout<<' ';
        cout<<q[i];
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