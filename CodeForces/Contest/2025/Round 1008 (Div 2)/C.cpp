#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n; n *= 2;
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin>>b[i];

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<ll> a(n+1);
    a[0] = b[0];

    ll calc = 0;
    // Llenar pares
    for(int i = 2, j = 1; i <= n; i += 2, j++){
        a[i] = b[j];
        calc += b[j];
    }

    // Llenar impares
    for(int i = 3, j = n-1; i < n; i += 2, j--){
        a[i] = b[j];
        calc -= b[j];
    }

    a[1] = calc + a[0];

    for(int i = 0; i <= n; i++){
        if(i) cout<<' ';
        cout<<a[i];
    }
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