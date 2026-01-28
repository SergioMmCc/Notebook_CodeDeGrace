#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 500000

vector<int> numbers(MAXN);
int dp[MAXN], med[MAXN];
int n, k;

bool test(int m){
    for(int i = 0; i < n; i++){
        if(numbers[i] < m)
            med[i] = -1;
        else
            med[i] = 1;
    }
    dp[0] = med[0];
    for(int i = 1; i < n; i++){
        if(i % k == 0) 
            dp[i] = max(dp[i-k], med[i]);
        else{
            dp[i] = dp[i-1] + med[i];
            if(i > k)
                dp[i] = max(dp[i-k], dp[i]);
        }
    }
    return dp[n-1] > 0;
}

void solver() {
    cin>>n>>k;
    for(int i = 0; i < n; i++)
        cin>>numbers[i];
    int l = 1, r = 1e9;
    while(l <= r){
        int m = (l+r)/2;
        if(test(m))
            l = m+1;
        else
            r = m-1;
    }
    cout<<r<<endl;
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