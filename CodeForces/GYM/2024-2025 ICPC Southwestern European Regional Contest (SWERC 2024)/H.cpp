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
typedef pair<string, int> psi;

void solver(){
    int n; cin>>n;
    map<string, int> T;
    for(int i = 0; i < n; i++){
        string name; cin>>name;
        T[name]++;
    }

    psi ans = {" ", 0};
    for(const auto& par : T){
        if(par.se > ans.se) ans = {par.fi, par.se};
    }

    cout<<ans.fi<<endl;
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