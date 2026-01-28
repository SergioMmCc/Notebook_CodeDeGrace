#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    int x = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        a[i] = x + save;
        x = max(x, a[i]);
    }

    for(int i = 0; i < n; i++){
        if(i > 0) cout<<' ';
        cout<<a[i];
    }

    cout<<endl;
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