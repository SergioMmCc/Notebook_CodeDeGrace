#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, string> pis;

void solver(){
    pis maxi1 = {0, ""};
    for(int i = 0; i < 4; i++){
        string save; int num; cin>>save>>num;
        maxi1 = max(maxi1, {num, save});
    }

    pis maxi2 = {0, ""};
    for(int i = 0; i < 4; i++){
        string save; int num; cin>>save>>num;
        maxi2 = max(maxi2, {num, save});
    }

    if(maxi1 < maxi2) swap(maxi1, maxi2);
    cout<<maxi1.se<<" beats "<<maxi2.se<<endl;
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