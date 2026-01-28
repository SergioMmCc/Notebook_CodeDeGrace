#include<bits/stdc++.h>
using namespace std;

void solver() {
    int i = 1, j = 999, l, r;
    while(i < j) {
        l = (j-i)/3 + i, r = 2*(j-i)/3 + i;
        cout<<"? "<<l<<' '<<r<<endl;
        int ans, x = l*r, y = l*(r+1);
        cin>>ans;
        if(ans == x)
            i = r+1;
        else if(ans == y) {
            i = l+1;
            j = r;
        }
        else
            j = l;
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