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

int dist(vector<int>& a, vector<int>& b){
    int ans = 0;
    for(int i = 0; i < a.sz; i++) ans += abs(a[i] - b[i]);
    return ans;
}

void upd(vector<int>& mini, vector<bool>& used, vector<vector<int>>& p, int last){
    for(int i = 0; i < mini.sz; i++){
        if(used[i]) continue;
        mini[i] = min(mini[i], dist(p[i], p[last]));
    }
}

void solver(){
    int n, l, k; cin>>n>>l>>k;
    vector<string> ans;
    map<int, string> name;
    vector<vector<int>> p(n, vector<int>(l));
    for(int i = 0; i < n; i++){
        string s; cin>>s; name[i] = s;
        for(int j = 0; j < l; j++) cin>>p[i][j];
    }

    vector<int> dis(n);

    int d = -1, ind = 0;
    // Seleccionar el primero
    for(int i = 1; i < n; i++){
        int aux = dist(p[0], p[i]);
        if(aux > d){
            d = aux;
            ind = i;
        }
    }

    ans.pb(name[ind]);

    vector<int> mini(n, 1e9);
    vector<bool> used(n); used[ind] = 1;
    for(int i = 1; i < k; i++){
        upd(mini, used, p, ind);
        d = -1;
        ind = 0;

        for(int j = 0; j < n; j++){
            if(used[j]) continue;
            if(mini[j] > d){
                d = mini[j];
                ind = j;
            }
        }

        ans.pb(name[ind]);
        used[ind] = 1;
    }

    for(int i = 0; i < k; i++) cout<<ans[i]<<endl;
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