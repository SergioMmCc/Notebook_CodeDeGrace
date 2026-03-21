#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ld inf = 1000000.0;

ld dist(pii a, pii b){
    return sqrt((ld)((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se)));
}

void solver(){
    int n, k, im; cin>>n>>k>>im;
    ld m = (ld)im;

    vector<pii> c(n);
    for(int i = 0; i < n; i++) cin>>c[i].fi>>c[i].se;
    vector<piii> r(k);
    for(int i = 0; i < k; i++){
        cin>>r[i].fi.fi>>r[i].fi.se>>r[i].se;
        r[i].fi.fi--;
        r[i].fi.se--;
    }

    vector<vector<ld>> d(n, vector<ld>(n, inf));
    for(int u = 0; u < n; u++){
        int v = (u + 1) % n;
        d[u][u] = 0.0;
        d[u][v] = d[v][u] = dist(c[u], c[v]);
    }

    int ans = 1e9 + 1;
    for(int i = 1; i < (1 << k); i++){
        vector<vector<ld>> aux = d;
        int count = 0;
        for(int j = 0; j < k; j++){
            if((1 << j) & i){
                // cout<<"i -> "<<i<<" j-> "<<j<<endl;
                aux[r[j].fi.fi][r[j].fi.se] = aux[r[j].fi.se][r[j].fi.fi] = dist(c[r[j].fi.fi], c[r[j].fi.se]);
                count += r[j].se;
            }
        }

        if(count > ans) continue;
        // cout<<"here"<<endl;

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                for(int z = 0; z < n; z++){
                    aux[y][z] = min(aux[y][z], aux[y][x] + aux[x][z]);
                }
            }
        }

        ld maxi = 0.0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                maxi = max(maxi, aux[x][y]);
            }
        }

        // cout<<"maxi -> "<<maxi<<endl;
        if(maxi <= m) ans = count;
    }

    cout<<ans<<endl;
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