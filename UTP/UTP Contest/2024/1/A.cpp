#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    string x, y;
    bool biggest = 0;
    bool cond = 1;
    for(int i = 0; i < 2*n - 2; i++){
        string save; cin>>save;
        if(save.sz == n - 1){
            if(!biggest){
                biggest = 1;
                x = save;
            }
            else y = save;
        }
    }

    reverse(x.begin(), x.end());

    if(x == y) cout<<"YES"<<endl;
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