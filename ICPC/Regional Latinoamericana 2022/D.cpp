#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll = long long;
using ld = long double;

void solver(){
    int n, h, w;cin>>n>>h>>w;
    for(int i = 0; i < n; i++){
        char tow, toh; cin>>tow>>toh;
        if(h == 0)cout<<"N ";
        else {
            if(tow == 'Y' || w == 0){
                cout<<"Y ";
                h--;
                w++;
            }
            else cout<<"N ";
        }
        if(w == 0)cout<<'N';
        else {
            if(toh == 'Y' || h == 0){
                cout<<"Y";
                w--;
                h++;
            }
            else cout<<"N";
        }
        cout<<endl;
    }
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