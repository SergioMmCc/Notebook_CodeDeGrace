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
const ld PI = 3.14159265358979323;

void solver(){
    int n, iv; cin>>n>>iv;
    ld v = (ld)iv;
    
    ld maxi = -1.0; int index = 0;
    for(int i = 1; i <= n; i++){
        int h, r; cin>>h>>r;
        ld vol = PI * (ld) h * (ld)(r * r);
        if(vol < v) continue;
        if(maxi == -1.0 || vol < maxi){
            index = i;
            maxi = vol;
        }
    }

    if(!index) cout<<"impossible"<<endl;
    else cout<<index<<endl;
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