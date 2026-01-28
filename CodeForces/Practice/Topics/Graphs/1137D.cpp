#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    bool cond = 0;
    while(!cond){
        cout<<"next 0"<<endl;
        int num; cin>>num;
        string save;
        for(int i = 0; i < num; i++) cin>>save;
        
        cout<<"next 0 1"<<endl;
        cin>>num;
        for(int i = 0; i < num; i++){
            cin>>save;
            if(!cond){
                bool n0 = 0, n1 = 0;
                for(int j = 0; j < save.sz; j++){
                    if(save[j] == '0') n0 = 1;
                    else if(save[j] == '1') n1 = 1;
                }

                cond = n1 & n0;
            }
        }
    }

    cond = 0;
    while(!cond){
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        int num; cin>>num;
        string save;
        for(int i = 0; i < num; i++) cin>>save;
        if(num == 1) cond = 1;
    }

    cout<<"done"<<endl;
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