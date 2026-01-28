#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int x, y; cin>>x>>y;
    if(y == x+1){
        cout<<"YES"<<endl;
        return;
    }

    x -= 8;
    if(y > x){
        cout<<"NO"<<endl;
        return;
    }

    if((x - y) % 9 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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