#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int t; cin>>t;
    string s; cin>>s;
    while(s == "ROUND"){
        int m, b; cin>>m>>b;
        if(b <=  m / 3) cout<<"PLAY"<<endl;
        else cout<<"SKIP"<<endl;

        cin>>s;
    }
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}