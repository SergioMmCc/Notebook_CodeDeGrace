#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    int n; cin>>n;
    bool cond = 1;

    int lastA = 0, lastB = 0;
    while(n--){
        int a, b; cin>>a>>b;
        if(a < lastA || b < lastB) cond = 0;
        lastA = a;
        lastB = b;
    }

    cout<<(cond ? "yes" : "no")<<endl;

    return 0;
}