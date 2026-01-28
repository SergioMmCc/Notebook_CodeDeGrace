#include<bits/stdc++.h>
using namespace std;

void solver() {
    int i = 1, j = 999, m;
    while(i < j) {
        m = (i+j)/2;
        cout<<"? 1 "<<m<<endl;
        int ans;
        cin>>ans;
        if(ans == m)
            i = m+1;
        else
            j = m;
    }
    cout<<"! "<<i<<endl;
}

int main () {
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}