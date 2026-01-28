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

void solver(){
    int n; cin>>n;
    if(n <= 360){
        cout<<0<<endl;
        return;
    }

    if(n <= 540){
        cout<<min(30, n - 360)<<endl;
        return;
    }

    if(n <= 600){
        cout<<max(30, min(45, n - 540))<<endl;
        return;
    }

    cout<<max(45, n - 600)<<endl;
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