#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m, r; cin>>n>>m>>r;
    vector<pii> teams(n+1);
    int totalP = 0;
    for(int i = 1; i <= n; i++){
        string info; cin>>info;
        int a = 0, p = 0;
        for(int j = 0; j < m; j++) if(info[j] == 'P') p++;
        totalP += p;
        teams[i] = {p, i};
    }

    for(int i = 0; i < totalP; i++){
        int team = n;
        while(!teams[team].first) team--;
        teams[team].first--;
        string x, ans; cin>>x>>ans;
        int countY = 0;
        for(int j = 0; j < ans.sz; j++){
            if(ans[j] == 'y') countY++;
        }

        if(countY < 4) continue;

        int dif = countY - 3;

        // Asignar valores
        int pos = team - dif;
        pii aux = teams[pos];
        teams[pos] = teams[team];

        pos++;
        while(pos <= team){
            pii aux2 = teams[pos];
            teams[pos] = aux;
            aux = aux2;
            pos++;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout<<teams[i].first<<' '<<teams[i].second<<endl;
    // }
    for(int i = 1; i <= n; i++){
        if(teams[i].second == r) cout<<i<<endl;
    }
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