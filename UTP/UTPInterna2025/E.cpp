#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1e5 + 1;
int components;
vector<int> leader(maxn), sizen(maxn), maxi(maxn);
map<string, int> T; map<int, string> r; map<int, int> hours;

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = i;
        maxi[i] = i;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(leaderU != leaderV){
        if(sizen[leaderV] > sizen[leaderU]) swap(leaderU, leaderV);

        int mu = maxi[leaderU], mv = maxi[leaderV];
        int hu = hours[mu], hv = hours[mv];
        if(hv > hu) maxi[leaderU] = mv;
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        components--;
    }
}

void solver(){
    int n, m; cin>>n>>m;
    initDSU(n);
    for(int i = 1; i <= n; i++){
        string name; int h; cin>>name>>h;
        T[name] = i;
        r[i] = name;
        hours[i] = h;
    }

    for(int i = 0; i < m; i++){
        string name1, name2; cin>>name1>>name2;
        int u = T[name1], v = T[name2];
        join(u, v);
    }

    vector<string> ans;
    for(int i = 1; i <= n; i++){
        if(find(i) != i) continue;
        ans.pb(r[maxi[i]]);
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.sz; i++){
        cout<<ans[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case "<<i<<":"<<endl;
        solver();
    }

    return 0;
}