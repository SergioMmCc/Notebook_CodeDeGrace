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

// n vertices
// Complejidad: O(v * e)

const int maxn = 200;
vector<int> graph[maxn];
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v){
    if(used[v])
        return 0;
    used[v] = 1;
    for(int to : graph[v]) {
        if(mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

void solver(){
    for(int i = 0; i < maxn; i++) graph[i].clear();

    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        ll num; cin>>num;
        for(int j = 0; j < 60; j++){
            if(num & (1LL << j)) graph[i].pb(j+1);
        }
    }

    int ans = n;
    n = max(n, 60);

    mt.assign(n + 1, -1);
    vector<bool> used1(n + 1, 0);
    for(int v = 1; v <= n; v++){
        for(int to : graph[v]){
            if(mt[to] == -1){
                mt[to] = v;
                used1[v] = 1;
                break;
            }
        }
    }
    for(int v = 1; v <= n; v++){
        if(used1[v]) continue;
        used.assign(n + 1, 0);
        try_kuhn(v);
    }

    for(int i = 1; i <= n; ++i)
        if(mt[i] != -1) ans--;

    cout<<ans<<endl;
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