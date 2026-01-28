#include<bits/stdc++.h>
#define endl '\n'
using namespace std; 

int main() {
    int n, r;
    cin>>n>>r;
    int aux = 1 << n;
    if(r == 1) {
        cout<<n<<endl;
        return 0;
    }
    int ans = 0;
    int resta = 1;
    // cout<<aux<<endl;
    while(r <= aux){
        aux -= resta;
        resta *= 2;
        ans++;
        // cout<<"aux -> "<<aux<<" resta -> "<<resta<<" ans -< "<<ans<<endl;
    }
    cout<<ans<<endl;
}