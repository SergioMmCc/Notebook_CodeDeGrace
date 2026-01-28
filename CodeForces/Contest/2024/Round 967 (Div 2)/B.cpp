#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n; cin>>n;
    if(n % 2 == 0){
        cout<<"-1"<<endl;
        return;
    }
    else{
        cout<<'1';
        for(int i = 2; i <= n; i++){
            if(i % 2 == 0)
                cout<<' '<<i+1;
            else
                cout<<' '<<i-1;
        }
        cout<<endl;
    }
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