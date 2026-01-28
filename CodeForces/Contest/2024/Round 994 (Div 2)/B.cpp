#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    string s; cin>>s;
    int spos = -1, ppos = n;
    for(int i = 0; i < n; i++){
        if(s[i] == 's') spos = i;
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'p') ppos = i;
    }

    if(spos > ppos){
        cout<<"NO"<<endl;
        return;
    }

    if(spos > 0 && ppos < n - 1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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