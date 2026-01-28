

#include <bits/stdc++.h>
using namespace std;

const long long int inf = 1e6+1;

int n, dp[1000005][3][3];
string S[1000005], vocals = "AEIOUY";

int isConsonant(char c){
    for(auto i:vocals)
        if(c == i) return -3;
        
    return 1;
}

long long int solver(int r,int i,int sum){
    if(r >= n && sum <= 2) return 0;
    if(i >= S[r].size() || i > 2 ) return inf;
    sum = max(sum + isConsonant(S[r][i]),0);
    if(sum > 2) return inf;
    if(dp[r][i][sum] != -1) return dp[r][i][sum];
    return dp[r][i][sum] = min(solver(r,i+1,sum),solver(r+1,0,sum))+1;
    
}
int main()
{
    cin>>n;
    for(int i =0; i < n; i++)cin>>S[i];
    memset(dp,-1, sizeof dp);
    long long int answ = solver(0,0,0);
    if(answ >= inf || answ < 0) cout<<"*\n";
    else cout<<answ<<"\n";
}
 