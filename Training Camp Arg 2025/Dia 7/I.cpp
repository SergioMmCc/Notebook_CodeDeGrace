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

const ld inf = 1e9, ep = 0.000001;

bool check(ld m, vector<int>& a, int n, int k){
    vector<ld> ps(n); ps[0] = (ld)a[0] - m;
    for(int i = 1; i < n; i++) ps[i] = ps[i-1] + (ld)a[i] - m;
    vector<ld> d(n+1, inf); d[0] = 0.0;

    int till = 0;
    for(int i = 0; i < n; i++){
        auto it = upper_bound(d.begin(), d.end(), ps[i]);
        if(it == d.begin()) continue;
        int index = it - d.begin();
        d[index] = ps[i];
        if(i == n - 1) till = index;
    }

    return till >= k;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ld l = 1.0, r = 1000.0;
    while(l + ep < r){
        ld m = (l + r) / 2;
        bool cond = check(m, a, n, k);
        if(cond) l = m;
        else r = m;
    }

    cout<<fixed<<setprecision(6)<<l<<endl;
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