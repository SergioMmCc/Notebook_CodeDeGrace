#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    string password, ans = ""; cin>>password;
    char add;
    ans+=password[0];
    if(password.size() == 1){
        if(password[0] == 'a'){
            ans+="b";
        }
        else{
            ans+="a";
        }
        cout<<ans<<endl;
        return;
    }
    
    int maxLen = 1, pos, parcialCount = 1, parcialPos = 0;
    for(int i = 1; i < password.size(); i++) {
        if(password[i] == password[i-1]) {
            parcialCount++;
        }
        else{
            if(parcialCount > maxLen){
                pos = parcialPos;
                maxLen = parcialCount;
            }
            parcialPos=i;
            parcialCount = 1;
        }
    }
    if(parcialCount > maxLen){
        pos = parcialPos;
        maxLen = parcialCount;
    }
    
    if(maxLen == 1){
        if(password[password.size()-1] == 'a')
            password+='b';
        else
            password+='a';
        cout<<password<<endl;
        return;
    }
    
    if(maxLen >= 3) {
        if(password[pos] == 'a')
            add = 'b';
        else
            add = 'a';
    }
    else if(maxLen == 2) {
        if(password[pos] == 'a')
            add='b';
        else
            add='a';
    }
    pos++;
    for(int i = 1; i < password.size(); i++) {
        if(i==pos)
            ans+=add;
        ans+=password[i];
    }
    cout<<ans<<endl;
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