#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 5e5 + 1;
vector<set<int>> tree(maxn);
vector<queue<pair<int, pii>>> q(maxn);

void solver(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) tree[i].clear();
    vector<int> a(n+1), freq(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<bool> ans(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        if(a[u] == a[v]) ans[a[u]] = 1;
        else{
            if(!ans[a[u]] && tree[a[u]].find(v) != tree[a[u]].end()) ans[a[u]] = 1;
            if(!ans[a[v]] && tree[a[v]].find(u) != tree[a[v]].end()) ans[a[v]] = 1;
        }
        tree[a[u]].insert(v);
        tree[a[v]].insert(u);
    }

    for(int i = 1; i <= n; i++) cout<<(ans[i] ? '1' : '0');
    cout<<endl;
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