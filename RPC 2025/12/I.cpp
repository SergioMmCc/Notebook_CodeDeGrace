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

void solver(){
    int n, m, cur, sel, wan; cin>>n>>m>>cur>>sel>>wan;
    int pag = (n + m - 1) / m;
    // cout<<"pag -> "<<pag<<endl;
    int l = n, r = 0;
    vector<bool> alr(n+1), use(n+1);

    for(int i = 0; i < sel; i++){
        int num; cin>>num;
        alr[num] = 1;
    }
    for(int i = 0; i < wan; i++){
        int num; cin>>num;
        use[num] = 1;
    }

    for(int i = 1; i <= n; i++){
        if((alr[i] && !use[i]) || (!alr[i] && use[i])){
            l = min(l, i);
            r = max(r, i);
        }
    }

    l = (l + m - 1) / m;
    r = (r + m - 1) / m;

    if(!r){
        cout<<0<<endl;
        return;
    }
    // cout<<"l -> "<<l<<" r -> "<<r<<endl;

    int ans = 0;
    if(l >= cur){
        ans = r - cur;
    }
    else if(r <= cur){
        ans = cur - l;
    }
    else{
        ans = r - l + min(cur - l, r - cur);
    }
    // cout<<"ans -> "<<ans<<endl; 

    for(int p = 1; p <= pag; p++){
        int sw = 0, snw = 0, tw = 0, ts = 0, tot = 0;
        for(int i = 1; i <= m; i++){
            int ele = (p - 1)*m + i;
            if(ele > n) break;

            tot++;
            if(use[ele]) tw++;
            if(alr[ele]) ts++;
            if(alr[ele] && use[ele]) sw++;
            if(alr[ele] && !use[ele]) snw++;
        }

        int mini = m;
        mini = min(mini, 1 + tot - tw);
        mini = min(mini, 1 + tw);
        mini = min(mini, tw - sw + snw);

        // cout<<"pag -> "<<p<<" mini -> "<<mini<<" tot -> "<<tot<<" tw -> "<<tw<<" ts -> "<<ts<<" sw -> "<<sw<<" snw -> "<<snw<<endl;
        ans += mini;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}