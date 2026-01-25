#include <bits/stdc++.h>

using namespace std;

bool notVoid(string M){
    for(auto i: M)
        if(i != '-')
            return true;
    return false;
}

bool isVoid(string M){
    for(auto i: M)
        if(i != '*')
            return true;
    return false;
}

int main()
{
    int r,c,k;
    string P[1005],K[1005];
    cin>>r>>c>>k;
    
    for(int i=0; i < r; i++) cin>>P[i]>>K[i];
    
    for(int i=0; i < r; i++)
        if(notVoid(K[i]) && isVoid(P[i])){
            cout<<"N\n";
            return 0;
        }
        
    cout<<"Y\n";
    
    return 0;
}
