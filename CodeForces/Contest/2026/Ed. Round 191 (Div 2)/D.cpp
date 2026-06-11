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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vi& a, int n, int m){
    vi last(m, -1);
    for(int i = 0; i < n; i++){
        if(last[a[i]] != -1 && last[a[i]] != i-1) return 0;
        last[a[i]] = i;
    }
    return 1;
}

void solver(){
    int n; cin>>n;
    vi a(n);

    // Comprimir
    indexed_set cmp;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        cmp.insert(a[i]);
    }
    int m = sz(cmp);

    for(int i = 0; i < n; i++) a[i] = cmp.order_of_key(a[i]);

    if(check(a, n, m)){
        cout<<"YES"<<endl;
        return;
    }

    vector<vii> segs(m);
    for(int i = 0; i < n; i++){
        if(segs[a[i]].empty() || segs[a[i]].back().se != i-1) segs[a[i]].pb({i, i});
        else segs[a[i]].back().se++;
    }

    for(int i = 0; i < m; i++){
        if(sz(segs[i]) >= 4){
            cout<<"NO"<<endl;
            return;
        }

        if(sz(segs[i]) == 3){
            pii x = segs[i][0], y = segs[i][1], z = segs[i][2];
            vi aux = a;
            if(x.fi == x.se && z.fi - y.se == 2){
                swap(aux[x.fi], aux[z.fi - 1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[x.fi], aux[z.fi - 1]);
            }
            if(z.fi == z.se && y.fi - x.se == 2){
                swap(aux[z.fi], aux[y.fi - 1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[z.fi], aux[y.fi - 1]);
            }
            
            cout<<"NO"<<endl;
            return;
        }

        if(sz(segs[i]) == 2){
            pii x = segs[i][0], y = segs[i][1];
            vi aux = a;
            if(x.fi == x.se){
                swap(aux[x.fi], aux[y.fi - 1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[x.fi], aux[y.fi - 1]);

                if(y.se < n-1){
                    swap(aux[x.fi], aux[y.se + 1]);
                    if(check(aux, n, m)){
                        cout<<"YES"<<endl;
                        return;
                    }
                    swap(aux[x.fi], aux[y.se + 1]);
                }
            }

            if(y.se == y.fi){
                swap(aux[y.fi], aux[x.se + 1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[y.fi], aux[x.se + 1]);

                if(x.fi){
                    swap(aux[y.fi], aux[x.fi - 1]);
                    if(check(aux, n, m)){
                        cout<<"YES"<<endl;
                        return;
                    }
                    swap(aux[y.fi], aux[x.fi - 1]);
                }
            }

            // Agregar la condicion de cambiar uno de los extremos hacia la posicion del medio sin importar que los bloques sean grandes
            if(y.fi - x.se == 2){
                swap(aux[x.fi], aux[x.se+1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[x.fi], aux[x.se+1]);

                swap(aux[y.se], aux[x.se+1]);
                if(check(aux, n, m)){
                    cout<<"YES"<<endl;
                    return;
                }
                swap(aux[y.se], aux[x.se+1]);
            }

            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    return;
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