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

void solver(){
    int n, m; cin>>n>>m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    map<string, int> T;
    T["ppp"] = 1;
    T["pp"] = 2;
    T["p"] = 3;
    T["mp"] = 4;
    T["mf"] = 5;
    T["f"] = 6;
    T["ff"] = 7;
    T["fff"] = 8;

    vector<pii> b(m);
    for(int i = 0; i < m; i++){
        int save; string s; cin>>save>>s;
        b[i] = {save, T[s]};
    }

    vector<vector<int>> nota(9);
    for(int i = 1; i < m; i++){
        for(int li = b[i-1].fi; li < b[i].fi; li++){
            nota[b[i-1].se].pb(a[li]);
        }
    }

    for(int li = b[m-1].fi; li <= n; li++){
        nota[b[m-1].se].pb(a[li]);
    }

    for(int i = 1; i <= 8; i++){
        sort(nota[i].begin(), nota[i].end());
    }

    ll count = 0;
    for(int i = 1; i <= 7; i++){
        for(int val : nota[i]){
            for(int j = i + 1; j <= 8; j++){
                vector<int>::iterator it = upper_bound(nota[j].begin(), nota[j].end(), val);
                if(it != nota[j].begin()){
                    --it;
                    count += (ll)distance(nota[j].begin(), it) + 1;
                }
            }
        }
    }

    cout<<count<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}