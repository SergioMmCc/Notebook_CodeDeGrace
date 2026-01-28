#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int inf = 2e9;
map<string, vector<int>> T;

int binarySearch(vector<int>& a, int i, int j, int s){
    int m;
    while(i <= j){
        m = (i + j) >> 1;
        if(a[m] == s) return m;
        else if(a[m] > s) j = m - 1;
        else i = m + 1;
    }

    return -i - 1;
}

int test(string testing, int u, int v){
    int ans = inf;
    if(T.find(testing) == T.end()) return ans;
    int index = binarySearch(T[testing], 0, T[testing].sz - 1, u);
    int l = -index - 2;
    int r = -index - 1;
    if(l >= 0) ans = min(ans, v + u - 2 * T[testing][l]);
    if(r < T[testing].sz){
        if(T[testing][r] < v) ans = min(ans, v - u);
        else ans = min(ans, 2 * T[testing][r] - u - v);
    }

    return ans;
}

void solver(){
    int n, q; cin>>n>>q;
    vector<string> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        T[a[i]].pb(i);
    }

    while(q--){
        int u, v; cin>>u>>v;
        if(u > v) swap(u, v);
        if(a[u][0] == a[v][0] || a[u][0] == a[v][1] || a[u][1] == a[v][0] || a[v][1] == a[u][1]){
            cout<<v - u<<endl;
            continue;
        }

        int ans = inf;
        if(a[u] == "BR" || a[u] == "GY"){
            ans = min(ans, test("BG", u, v));
            ans = min(ans, test("BY", u, v));
            ans = min(ans, test("GR", u, v));
            ans = min(ans, test("RY", u, v));
        }
        else if(a[u] == "BG" || a[u] == "RY"){
            ans = min(ans, test("BR", u, v));
            ans = min(ans, test("BY", u, v));
            ans = min(ans, test("GR", u, v));
            ans = min(ans, test("GY", u, v));
        }
        else{ //a[u] == "BY" || a[u] == "GR"
            ans = min(ans, test("BG", u, v));
            ans = min(ans, test("BR", u, v));
            ans = min(ans, test("GY", u, v));
            ans = min(ans, test("RY", u, v));
        }   

        if(ans == inf) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    T.clear();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}