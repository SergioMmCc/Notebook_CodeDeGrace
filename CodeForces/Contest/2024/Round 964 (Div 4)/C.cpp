#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, s, m;
    cin>>n>>s>>m;
    int l, r, lastStart = 0, nextStart;
    bool cond = false;
    while(n--) {
        cin>>l>>r;
        nextStart = l;
        if(nextStart - lastStart >= s)
            cond = true;
        lastStart = r;
    }
    nextStart = m;
    if(nextStart - lastStart >= s)
        cond = true;
    if(cond)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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