#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    int countPares = 0;
    long long mayorImpar = -1;
    vector<long long> pares;
    for(int i = 0; i < n; i++){
        long long save;cin>>save;
        if(save%2 == 0){
            countPares++;
            pares.push_back(save);
        }
        else
            mayorImpar = max(mayorImpar, save);
    }
    if(countPares == n)
        cout<<'0'<<endl;
    else {
        sort(pares.begin(), pares.end());
        for(int i : pares){
            if(i > mayorImpar){
                cout<<countPares+1<<endl;
                return;
            }
            mayorImpar += i;
        }
        cout<<countPares<<endl;
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}