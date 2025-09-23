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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;


struct comp{
    bool operator() (vector<int> a, vector<int> b){
        return a.sz > b.sz;
    }
};

void solver(){
    int n; cin>>n;
    int len = 0;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        int k; cin>>k;
        len = max(len, k);
        for(int j = 0; j < k; j++){
            int save; cin>>save;
            a[i].pb(save);
        }
    }
    sort(a.begin(), a.end(), comp());

    vector<int> ans(len);

    int i = 0;
    while(i < len){
        vector<int> pos;
        for(int j = 0; j < n; j++){
            if(i >= a[j].sz) break;
            pos.pb(j);
        }

        int choose = -1;
        while(choose == -1){
            int mini = 2e5 + 2;
            vector<int> aux;
            for(int j : pos){
                if(i >= a[j].sz){
                    aux.clear();
                    aux.pb(j);
                    break;
                }
                if(a[j][i] < mini){
                    mini = a[j][i];
                    aux.clear();
                    aux.pb(j);
                }
                else if(a[j][i] == mini) aux.pb(j);
            }

            if(aux.sz == 1) choose = aux[0];
            else{
                ans[i] = mini;
                mini = 2e5 + 1;
                i++;
                pos = aux;
                aux.clear();
            }
        }

        while(i < a[choose].sz){
            ans[i] = a[choose][i];
            i++;
        }
    }

    for(int i = 0; i < len; i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}