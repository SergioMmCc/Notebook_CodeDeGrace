#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int const mod = 1e9 + 7, MAXT = 1e4;
vector<int> preCalc[MAXT + 1];

void madePreCalc() {
    preCalc[1].push_back(0);preCalc[1].push_back(1);
    for(int i = 2; i <= MAXT; i++) {
        preCalc[i].resize(i+1);
        preCalc[i][i] = 1;
        for(int j = 1; j < i; j++) {
            int minPos = min(i-j, j);
            preCalc[i][i-j] = preCalc[j][minPos];
        }
        for(int j = 2; j <= i; j++)
            preCalc[i][j] = ((preCalc[i][j] % mod) + preCalc[i][j-1]) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    madePreCalc();
    int n;
    while(cin>>n) 
        cout<<preCalc[n][n]<<endl;
    
    return 0;
}