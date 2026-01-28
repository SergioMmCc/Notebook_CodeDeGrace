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
    int a, b, x, y; cin>>a>>b>>x>>y;
    if(a == b + 1){
        cout<<(a % 2 ? y : -1)<<endl;
        return;
    }
    if(a > b){
        cout<<-1<<endl;
        return;
    }

    if(y >= x){
        cout<<(b - a)*x<<endl;
        return;
    }

    int ans = 0;
    for(int i = a; i < b; i++){
        if(i % 2) ans += x;
        else ans += y;
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