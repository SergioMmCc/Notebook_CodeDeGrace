#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

int binarySearch(vector<ll>& a, int i, int j, ll search){
    int m;
    while(i <= j){
        m = (i + j) >> 1;
        if(a[m] == search) return m;
        if(a[m] > search) j = m - 1;
        else i = m + 1;
    }

    return -i;
}

ll calcCuantos(int index, vector<int>& donde, vector<ll>& cuantos){
    if(cuantos[index] != -1) return cuantos[index];
    if(!donde[index]) cuantos[index] = 0;
    else if(donde[index] >= donde.sz) cuantos[index] = 1;
    else cuantos[index] = 1 + calcCuantos(donde[index], donde, cuantos);
    return cuantos[index];
}

void solver(){
    ll n, x; cin>>n>>x;
    vector<ll> sum(n+1);
    for(int i = 1; i <= n; i++){
        ll save; cin>>save;
        sum[i] = sum[i-1] + save;
    }

    vector<int> donde(n+1);
    vector<ll> cuantos(n+1, -1);

    for(int i = 1; i <= n; i++){
        int index = binarySearch(sum, 1, n, sum[i-1] + x + 1);
        if(index < 0) index *= -1;
        if(index > n) continue;
        donde[i] = index+1;
    }

    for(int i = 1; i <= n; i++){
        if(cuantos[i] == -1) calcCuantos(i, donde, cuantos);
    }

    ll ans = (n * (n+1)) / 2;
    for(int i = 1; i <= n; i++) ans -= cuantos[i];

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