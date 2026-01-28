#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    // Todo ceros
    bool cero = 1;
    for(int i = 1; i <= n; i++){
        if(a[i]) cero = 0;
    }

    if(cero){
        cout<<0<<endl;
        return;
    }

    // Ceros solo en extremos o en medio
    bool medio = 0;
    bool leftI = 0;
    bool rightI = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] && !leftI) leftI = 1;
        if(!a[i] && leftI) medio = 1;
        if(a[i] && medio) rightI = 1;
    }

    if(rightI) cout<<2<<endl;
    else cout<<1<<endl;
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