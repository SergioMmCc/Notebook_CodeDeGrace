#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    ll n; cin>>n;
    ll count = 1;
    for(ll i = 2; count <= n && i * i < n; i++){
        if(n % i == 0){
            count += i;
            count += n / i;
        }
    }

    ll raiz = sqrt(n);
    if(raiz * raiz == n) count += raiz;

    if(count > n) cout<<"abundant"<<endl;
    else if(count == n) cout<<"perfect"<<endl;
    else cout<<"deficient"<<endl;
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