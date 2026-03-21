#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin>>a;
    int ans = 0;
    vector<bool> appear(10);
    for(int i = 0; i <= 11; i++){
        if(a[i] == '-') continue;
        appear[a[i] - '0'] = 1;
    }
    for(int i = 0; i <= 9; i++){
        if(appear[i]) ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}