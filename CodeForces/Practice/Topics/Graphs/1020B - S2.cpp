#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 1005;
vector<int> adj(maxn), ans(maxn);

void fillUp(int startingCycle, int x){
    while(x != startingCycle){
        ans[x] = ans[startingCycle];
        x = adj[x];
    }
}

void floyd(int x){
    int a = adj[x];
    int b = adj[adj[x]];

    while(a != b){
        if(ans[a]){
            fillUp(a, x);
            return;
        }
        a = adj[a];
        b = adj[adj[b]];
    }

    a = x;
    while(a != b){
        a = adj[a];
        b = adj[b];
    }

    int startingCycle = a;
    a = x;
    while(a != startingCycle){
        ans[a] = startingCycle;
        a = adj[a];
    }

    a = startingCycle;
    do{
        ans[a] = a;
        a = adj[a];
    } while(a != startingCycle);
}

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) cin>>adj[i];

    for(int i = 1; i <= n; i++){
        if(!ans[i]) floyd(i);

        if(i > 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
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