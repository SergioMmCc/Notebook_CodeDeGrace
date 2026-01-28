#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void change(int n, bool cond, vector<bool>& pos){
    for(int i = n; i <= 100; i++){
        if(!pos[i]) continue;
        if(i % n) pos[i] = !cond;
        else pos[i] = cond;
    }
}

void solver(){
    vector<bool> pos(101, 1);
    cout<<2<<endl;
    string ans; cin>>ans;
    if(ans == "equal"){
        cout<<2<<endl;
        return;
    }
    if(ans == "multiple"){
        cout<<1<<endl;
        return;
    }
    if(ans == "factor") change(2, 1, pos);
    else if(ans == "other") change(2, 0, pos);

    for(int i = 2; i <= 100; i++){
        if(!pos[i]) continue;
        cout<<i<<endl;
        cin>>ans;
        if(ans == "equal"){
            cout<<i<<endl;
            return;
        }
        if(ans == "multiple"){
            cout<<1<<endl;
            return;
        }
        if(ans == "factor") change(i, 1, pos);
        else if(ans == "other") change(i, 0, pos);
    }
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}