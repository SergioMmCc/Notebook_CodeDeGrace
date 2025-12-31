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

void solver(){
    int n, m; cin>>n>>m;
    int k = 0;
    int auxn = n, auxm = m;
    while((auxn >= 2 && auxm >= 1) || (auxn >= 1 && auxm >= 2)){
        k++;
        if(auxn > auxm){
            auxn -= 2;
            auxm--;
        }
        else{
            auxn--;
            auxm -= 2;
        }
    }

    cout<<k<<endl;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(all(a));
    vector<ll> suma;
    for(int i = 0; i < n / 2; i++) suma.pb(a[n-i-1] - a[i]);

    vector<ll> b(m);
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(all(b));
    vector<ll> sumb;
    for(int i = 0; i < m / 2; i++) sumb.pb(b[m-i-1] - b[i]);

    ll ans = 0;
    int l = 0, r = 0;
    auxn = n, auxm = m;
    for(int i = 0; i < k; i++){
        if(i) cout<<' ';

        if(auxn >= 2 && auxm >= 2){
            if(suma[l] > sumb[r]){
                ans += suma[l];
                l++;
                auxn -= 2;
                auxm--;
            }
            else{
                ans += sumb[r];
                r++;
                auxm -= 2;
                auxn--;
            }
        }
        else if(auxn >= 2){
            if(auxm == 1){
                ans += suma[l];
                l++;
                auxn -= 2;
                auxm--;
            }
            else{ // Quito 1 de b, pongo 2 de a
                // cout<<"here ";
                r--;
                ans -= sumb[r];
                ans += suma[l];
                l++;
                ans += suma[l];
                l++;
                auxn -= 3;
            }
        }
        else if(auxm >= 2){
            if(auxn == 1){
                ans += sumb[r];
                r++;
                auxm -= 2;
                auxn--;
            }
            else{
                l--;
                ans -= suma[l];
                ans += sumb[r];
                r++;
                ans += sumb[r];
                r++;
                auxm -= 3;
            }
        }

        cout<<ans;
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