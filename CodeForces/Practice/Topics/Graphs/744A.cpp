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

const int maxn = 1001;
int components;
vector<int> leader(maxn), sizen(maxn), is(maxn);

void initDSU(int n){
    components = n;
    for(int i = 1; i <= n; i++){
        leader[i] = i;
        sizen[i] = 1;
    }
}

int find(int u){
    if(leader[u] != u)
        leader[u] = find(leader[u]);
    return leader[u];
}

void join(int u, int v){
    int leaderU = find(u), leaderV = find(v);
    if(is[leaderV] || (sizen[leaderV] > sizen[leaderU] && !is[leaderU]))
        swap(leaderU, leaderV);
    
    if(leaderU != leaderV){    
        leader[leaderV] = leaderU;
        sizen[leaderU] += sizen[leaderV];
        // edges[leaderU] += edges[leaderV] + 1;
        components--;
    }
    // else edges[leaderU]++;
}

void updateAllLeaders(int n){
    for(int i = 1; i <= n; i++)
        find(i);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, m, k; cin>>n>>m>>k;
    initDSU(n);
    for(int i = 0; i < k; i++){
        int save; cin>>save;
        is[save] = 1;
    }

    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        join(u, v);
    }

    updateAllLeaders(n);
    
    int count = 0, maxi = 0, v = 0;
    for(int i = 1; i <= n; i++){
        if(is[i]){
            if(sizen[i] > maxi){
                maxi = sizen[i];
                v = i;
            }
        }

        else if(!is[leader[i]]) count++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!is[i]) continue;
        if(i == v) sizen[i] += count;
        ans += (sizen[i] * (sizen[i] - 1)) / 2;
    }

    ans -= m;
    cout<<ans<<endl;

    return 0;
}