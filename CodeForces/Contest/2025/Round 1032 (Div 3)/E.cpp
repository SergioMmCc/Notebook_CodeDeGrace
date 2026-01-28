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
    int l, r; cin>>l>>r;
    int ans = 18;
    for(int i = 0; i < 9; i++){
        if(!r || r - l >= 2) ans -= 2;
        else if(r - l == 1) ans--;
        r /= 10;
        l /= 10;
    }

    cout<<ans<<endl;
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