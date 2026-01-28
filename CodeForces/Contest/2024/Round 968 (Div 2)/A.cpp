#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver (){
    int n;cin>>n;
    string s; cin>>s;
    if(s[0] == s[n-1])cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}