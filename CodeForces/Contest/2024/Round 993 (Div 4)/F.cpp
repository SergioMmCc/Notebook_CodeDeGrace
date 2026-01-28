#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

#define int long long

void solver(){
    int n, m, q; cin>>n>>m>>q;
    vector<int> a(n), b(m);
    ll A = 0, B = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        A += a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
        B += b[i];
    }

    unordered_set<ll> ap, bp;
    for(int i = 0; i < n; i++) ap.insert(A - a[i]);
    for(int i = 0; i < m; i++) bp.insert(B - b[i]);

    while(q--){
        int x; cin>>x;
        bool cond = 0;
        for(int i = 1; !cond && i*i <= abs(x); i++){
            if(abs(x) % i == 0){
                if((ap.find(i) != ap.end() && bp.find(x / i) != bp.end()) ||
                   (ap.find(x / i) != ap.end() && bp.find(i) != bp.end()) ||
                   (ap.find(-i) != ap.end() && bp.find(-x/i) != bp.end()) || 
                   (ap.find(-x/i) != ap.end() && bp.find(-i) != bp.end()))
                   cond = 1;
            }
        }

        if(cond) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}