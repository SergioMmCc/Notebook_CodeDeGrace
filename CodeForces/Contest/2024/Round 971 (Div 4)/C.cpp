#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver(){
    int x, y, k;cin>>x>>y>>k;
    int jumpsX = (x + k - 1) / k;
    int jumpsY = (y + k - 1) / k;
    if(jumpsX > jumpsY)
        cout<<2*jumpsX - 1<<endl;
    else
        cout<<2*jumpsY<<endl;
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}