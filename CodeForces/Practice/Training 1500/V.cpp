#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n, k, d; cin>>n>>k>>d;
    vector<int> a(n + 1), b(k + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= k; i++) cin>>b[i];

    int ans = 0;
    for(int i = 1; i <= min(d, 2*n + 4); i++){

        int aux = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == j) aux++;
        }

        aux += (d - i) / 2;
        ans = max(ans, aux);

        int bi = b[i % k];
        if(i % k == 0) bi = b[k];

        for(int j = 1; j <= bi; j++) a[j]++;
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