#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return;
    }

    int op = 2;
    int num = 4;
    while(num < n){
        op++;
        num = 2*(num + 1);
    }

    cout<<op<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}