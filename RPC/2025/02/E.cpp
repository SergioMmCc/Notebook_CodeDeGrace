#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int an, ak, ap; cin>>an>>ak>>ap; an++;
    ld n = (ld)an, k = (ld)ak, p = (ld)ap;
    ld pr = (ld)p / 100.0;

    ld cont = (n - k) * (1.0 - pr) + (n + n - k + 3.0) * pr;
    ld bac = (n - k + 1.0) * pr + (n + n - k + 4.0) * (1.0 - pr);
    ld res = 3.0 + n;

    if(cont < res && cont < bac) cout<<"continue"<<endl;
    else if(res < bac) cout<<"restart"<<endl;
    else cout<<"backspace"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}