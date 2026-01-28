#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int a1, a2, b1, b2; cin>>a1>>a2>>b1>>b2;
    int result = 0;
    if((a1 > b1 && a2 >= b2) || (a1 >= b1 && a2 > b2))
        result+=2;
    if((a1 > b2 && a2 >= b1) || (a1 >= b2 && a2 > b1))
        result+=2;
    cout<<result<<endl;
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