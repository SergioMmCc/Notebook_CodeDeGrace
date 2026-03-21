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
#define PI (acos(-1.0L))

void solver(){
    int na, ra; cin>>na>>ra;
    ld n = (ld)na, r = (ld)ra;

    ld use = sin(PI / n);
    cout<<fixed<<setprecision(8)<<(r * use) / (1.0 - use)<<endl;
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