#include<bits/stdc++.h>
using namespace std;
#define endl '\n'



void solver() {
    int n;cin>>n;
    if(n==1) {
        cout<<"1"<<endl<<"1"<<endl;
        return;
    }
    if(n==2) {
        cout<<"2"<<endl<<"2 1"<<endl;
        return;
    }
    if(n==3) {
        cout<<"2"<<endl<<"1 2 2"<<endl;
        return;
    }
    if(n==4) {
        cout<<"3"<<endl<<"1 2 2 3"<<endl;
        return;
    }
    if(n == 5) {
        cout<<"3"<<endl<<"1 2 2 3 3"<<endl;
        return;
    }
    cout<<"4"<<endl<<"1";
    for(int i = 2; i <= n; i++) {
        if(i % 4 == 0) 
            cout<<" 4";
        else if(i % 4 == 1)
            cout<<" 1";
        else if(i % 4 == 2)
            cout<<" 2";
        else 
            cout<<" 3";
    }
    cout<<endl;
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