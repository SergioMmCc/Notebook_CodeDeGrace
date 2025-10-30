#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int maxn = 200005;
vector<int> leader1(maxn), leader2(maxn), sizen1(maxn), sizen2(maxn), maxi(maxn);

void initDSU(int n){
    for(int i = 1; i <= n; i++){
        leader1[i] = i;
        leader2[i] = i;
        sizen1[i] = 1;
        sizen2[i] = 1;
        maxi[i] = i;
    }
}

int find1(int u){
    if(leader1[u] != u)
        leader1[u] = find1(leader1[u]);
    return leader1[u];
}

int find2(int u){
    if(leader2[u] != u)
        leader2[u] = find2(leader2[u]);
    return leader2[u];
}

void join1(int u, int v){
    int leaderU = find1(u), leaderV = find1(v);
    if(leaderU != leaderV){
        if(sizen1[leaderV] > sizen1[leaderU])
            swap(leaderU, leaderV);
        leader1[leaderV] = leaderU;
        sizen1[leaderU] += sizen1[leaderV];
    }
}

void join2(int u, int v, int x, int y){
    int leader1U = find1(u), leader1V = find1(v), leader2U = find2(u), leader2V = find2(v);
    if(leader1U != leader1V){
        if(sizen1[leader1V] > sizen1[leader1U]){
            swap(leader1U, leader1V);
            swap(leader2U, leader2V);
        }
        
        leader1[leader1V] = leader1[leader1U];
        sizen1[leader1U] += sizen1[leader1V];
    }
    
    leader2[leader2V] = leader2[leader2U];
    sizen2[leader2U] += sizen2[leader2V];
    maxi[leader2U] = max(maxi[leader2U], maxi[leader2V]);
}

void solver(){
    int n, q; cin>>n>>q;
    initDSU(n);
    while(q--){
        int op, x, y; cin>>op>>x>>y;
        if(op == 1){
            join1(x, y);
        }
        else if(op == 2){
            int newL = find2(x);
            while(maxi[newL] < y){
                join2(newL, maxi[newL] + 1, x, y);
                newL = find2(x);
            }
        }
        else{
            cout<<(find1(x) == find1(y) ? "YES" : "NO")<<endl;
        }
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