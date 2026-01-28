#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    set<int> used;
    int pos1 = -1, posn = -1;
    for(int i = 1; i <= n; i++) used.insert(i);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] == 1) pos1 = i;
        if(a[i] == n) posn = i;
        if(used.find(a[i]) != used.end()) used.erase(a[i]);
    }

    if(used.sz){
        cout<<"? "<<*used.begin()<<' '<<(*used.begin() == 1 ? 2 : 1)<<endl;
        int ans; cin>>ans;
        cout<<(!ans ? "! A" : "! B")<<endl;
    }

    else{
        cout<<"? "<<pos1<<' '<<posn<<endl;
        int ans; cin>>ans;
        if(ans < n-1) cout<<"! A"<<endl;
        else if(ans >= n) cout<<"! B"<<endl;
        else{
            cout<<"? "<<posn<<' '<<pos1<<endl;
            cin>>ans;
            cout<<(ans == n-1 ? "! B" : "! A")<<endl;
        }
    }
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}