#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int binarySearch(vector<int>& A, int i, int j, int r){
    int m;
    while(i<=j){
        m = (i + j) / 2;
        if(A[m] == r)
            return m;
        if(A[m] < r)
            i = m+1;
        else
            j = m-1;
    }
    
    return -i-1;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n; cin>>n;
    vector<int> total(n+1);total[0] = -1;
    int maxLen = 0, totalLen = 0;
    for(int i = 1; i<=n; i++) {
        string save;cin>>save;
        int x = save.size();
        total[i] = total[i-1]+1+x;
        totalLen += x;
        maxLen = max(maxLen, x);
    }
    totalLen += n-1;

    int ans = 2e9;
    for(int i = maxLen; i <= totalLen; i++) {
        int j = 0, lastIndex = 0, aux = 0;
        while(j < n){
            aux++;
            j = binarySearch(total, j, n, lastIndex+i);
            if(j < 0)
                j = -j - 2;
            lastIndex = total[j] + 1;
        }
        ans = min(aux + i, ans);
    }
    cout<<ans<<endl;
    
    return 0;
}