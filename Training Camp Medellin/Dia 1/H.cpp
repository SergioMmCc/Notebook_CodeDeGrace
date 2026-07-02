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

int cntDiff(string& a, string& b){
    int cnt = 0;
    for(int i = 0; i < sz(a); i++) if(a[i] != b[i]) cnt++;

    return cnt;
}

void solver(){
    int n, m; cin>>n>>m;
    vs a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(cntDiff(a[i], a[j]) >= 3){
                cout<<-1<<endl;
                return;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(cntDiff(a[i], a[j]) == 2){
                string aux = "";
                bool cond = 0;
                for(int k = 0; k < sz(a[0]); k++){
                    if(a[i][k] != a[j][k]){
                        if(!cond) aux += a[i][k];
                        else aux += a[j][k];
                        cond = 1;
                    }
                    else aux += a[i][k];
                }

                int maxi = 0;
                for(int k = 0; k < n; k++) maxi = max(maxi, cntDiff(aux, a[k]));
                if(maxi <= 1){
                    cout<<aux<<endl;
                    return;
                }


                aux = ""; cond = 0; maxi = 0;
                for(int k = 0; k < sz(a[0]); k++){
                    if(a[i][k] != a[j][k]){
                        if(!cond) aux += a[j][k];
                        else aux += a[i][k];
                        cond = 1;
                    }
                    else aux += a[i][k];
                }
                for(int k = 0; k < n; k++) maxi = max(maxi, cntDiff(aux, a[k]));
                if(maxi <= 1){
                    cout<<aux<<endl;
                    return;
                }


                cout<<-1<<endl;
                return;
            }
        }
    }

    cout<<a[0]<<endl;
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