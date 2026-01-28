#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int lgn = 17;
const ll MAXN = 2e5 + 2;
typedef pair<ll, int> pli;

vector<int> bad(MAXN);
vector<ll> a(MAXN), s(MAXN);
pli rmq[MAXN][lgn + 1];

void dnq(int l, int r){
    if(l >= r)
        return;
    
    int lg = 31 - __builtin_clz(r - l + 1);
    int m = max(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]).second;
    
    dnq(l, m - 1);
    dnq(m + 1, r);
    
    ll sl = s[m - 1] - s[l - 1];
    ll sr = s[r] - s[m];
    
    if(a[m] > sl){
        bad[l] += 1;
        bad[m] -= 1;
    }
    if(a[m] > sr){
        bad[m + 1] += 1;
        bad[r + 1] -= 1;
    }
}

void solver(){
    int n, x;cin>>n>>x;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        rmq[i][0] = {a[i], i};
        bad[i] = 0;
    }
    
    //Crear sparse table
    for (int j = 1; j <= lgn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
    
    dnq(1, n);
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        bad[i] += bad[i - 1];
        ans += !bad[i]; //ans++ si bad[i] == 0
    }
    
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