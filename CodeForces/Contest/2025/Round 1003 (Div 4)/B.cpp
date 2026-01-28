#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    string name; cin>>name;
    bool cond = 0;
    for(int i = 1; !cond && i < name.sz; i++){
        if(name[i] == name[i-1]) cond = 1;
    }

    cout<<(cond ? 1 : name.sz)<<endl;
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