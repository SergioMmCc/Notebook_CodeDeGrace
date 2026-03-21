#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, ll> pii;

void solver(){
    string s; cin>>s;
    if(s == "first") cout<<"Nauuo and Votes"<<endl;
    else cout<<"Nauuo and Chess"<<endl;
}

ll main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}