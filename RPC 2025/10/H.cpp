#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int a1, b1, c1; cin>>a1>>b1>>c1;
    int a2, b2, c2; cin>>a2>>b2>>c2;

    int t1 = a1 + 2*b1 + 3*c1;
    int t2 = a2 + 2*b2 + 3*c2;

    if(t1 > t2) cout<<1;
    else if(t1 < t2) cout<<2;
    else cout<<0;
    cout<<endl;
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