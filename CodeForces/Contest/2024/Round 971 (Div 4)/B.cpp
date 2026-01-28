#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver(){
    int n; cin>>n;
    stack<int> a;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 0; j < 4; j++){
            if(s[j] == '#')
                a.push(j+1);
        }
    }
    while(!a.empty()){
        int i = a.top();
        cout<<i<<' ';
        a.pop();
    }
    cout<<endl;
    
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}