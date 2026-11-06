#include "../template.h"

void solve(){
    string s; cin>>s;
    s += s;
    int n = sz(s);
    vi fail(n, -1);

    int minRot=0;
    for1(i,n-1){
        char c = s[i];
        int j = fail[i-minRot-1];

        while(j != -1 && c != s[minRot+j+1]){
            if(c < s[minRot+j+1]) minRot = i-j-1;
            j = fail[j];
        }

        if(c != s[minRot+j+1]){
            if(c < s[minRot]) minRot = i;
            fail[i-minRot] = -1;
        }
        else{
            fail[i-minRot] = j+1;
        }
    }

    cout<<s.substr(minRot, n/2)<<endl;
}
