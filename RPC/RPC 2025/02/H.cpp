#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main(){
    ll n; cin>>n;

    ll i = 1;
    ll total = 1;
    while(total <= n){
        i++;
        total = i * (i + 1) / 2;
    }

    cout<<i-1<<endl;
    return 0;
}