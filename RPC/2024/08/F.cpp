#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXT 1000000

int const mod = 1e9 + 7;
vector<int> nElements(MAXT + 1), ans(MAXT + 1);

void preCalc(){
    ans[0] = 0; nElements[0] = 1;
    ans[1] = 1; nElements[1] = 1;

    for(int i = 2; i <= MAXT; i++){
        nElements[i] = (nElements[i-1] + nElements[i-2]) % mod;
        ans[i] = (((ans[i-1] + ans[i-2]) % mod) + nElements[i]) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    preCalc();
    int n, q;cin>>n>>q;
    while(q--){
        int s, t;
        cin>>s>>t;
        cout<<ans[t-s]<<endl;
    }
    return 0;
}