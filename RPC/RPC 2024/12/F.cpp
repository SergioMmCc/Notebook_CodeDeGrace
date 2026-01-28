#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define ps push_back
#define sz size()

void solver(){
    int n; cin>>n;
    map<string, int> T; //Nombre, index
    for(int i = 1; i <= n; i++){
        string name; cin>>name;
        T[name] = i;
    }

    int lastUp = 0;
    string winner = "suspicious";
    for(int i = 1; i <= n; i++){
        string name; cin>>name;
        int startIndex = T[name];
        int dif = startIndex - i;
        if(dif > lastUp){
            lastUp = dif;
            winner = name;
        }
    }

    cout<<winner<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}