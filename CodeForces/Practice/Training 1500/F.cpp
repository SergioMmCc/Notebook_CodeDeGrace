#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<int, int> pii;

void solver(){
    int n, m; ll v; cin>>n>>m>>v;
    vector<ll> a(n+1), sum(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }

    // Llenar pf y sf
    vector<int> pf(n+2), sf(n+2);
    ll count = 0;
    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1];
        count += a[i];
        if(count >= v){
            pf[i]++;
            count = 0;
        }
    }
    count = 0;
    for(int i = n; i > 0; i--){
        sf[i] = sf[i+1];
        count += a[i];
        if(count >= v){
            sf[i]++;
            count = 0;
        }
    }

    // Parte mas grande que Alicia puede comer
    // Poner j en la posicion minima
    int j = n;
    while(j > 0 && sf[j] < m){
        j--;
    }
    if(j == 0){
        cout<<-1<<endl;
        return;
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if(j <= i) j = i + 1;
        while(j <= n + 1 && pf[i] + sf[j] >= m){
            j++;
        }
        ans = max(ans, sum[j - 2] - sum[i]);
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