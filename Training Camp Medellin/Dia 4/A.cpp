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
    int n, m; cin>>n>>m;
    vector<vb> a(n, vb(m));
    vector<vi> col(2*m, vi(2*n));
    map<vi, int> comb;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int aux; cin>>aux;
            a[i][j] = aux;
            if(aux){
                col[2*j][2*i] = 1;
                col[2*j + 1][2*i + 1] = 1;
            }
            else{
                col[2*j][2*i + 1] = 1;
                col[2*j + 1][2*i] = 1;
            }
        }
    }

    for(int j = 0; j < 2*m; j++) comb[col[j]]++;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(sz(comb) == 2){
                cout<<"YES"<<endl;

                vi goal = comb.begin()->fi;

                vb ans1(n), ans2(m);
                for(int k = 0; k < 2*n; k += 2) if(goal[k]) ans1[k / 2] = 1;
                for(int k = 0; k < 2*m; k += 2) if(col[k] == goal) ans2[k / 2] = 1;

                for(int k = 0; k < n; k++) cout<<ans1[k]; cout<<endl;
                for(int k = 0; k < m; k++) cout<<ans2[k]; cout<<endl;

                return;
            }

            comb[col[2*j]]--;
            if(!comb[col[2*j]]) comb.erase(col[2*j]);
            comb[col[2*j + 1]]--;
            if(!comb[col[2*j + 1]]) comb.erase(col[2*j + 1]);

            // Hacer los cambios
            if(a[i][j]){
                col[2*j][2*i] =  0;
                col[2*j + 1][2*i + 1] = 0;
                col[2*j][2*i + 1] = 1;
                col[2*j + 1][2*i] = 1;
            }
            else{
                col[2*j][2*i + 1] = 0;
                col[2*j + 1][2*i] = 0;
                col[2*j][2*i] = 1;
                col[2*j + 1][2*i + 1] = 1;
            }

            comb[col[2*j]]++;
            comb[col[2*j + 1]]++;
        }
    }

    cout<<"NO"<<endl;
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