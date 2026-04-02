//https://cses.fi/problemset/task/1110

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1E9, MOD=1E9+7;


void solve(){
    string s;
    cin>>s;
    s += s;
    int n=s.size();

    vector<int> fail(n, -1);

    int minRot=0;

    for(int i=1; i<n; i++){
        char c = s[i];
        int j = fail[i-minRot-1];

        while(j != -1 && c != s[minRot+j+1]){
            if(c < s[minRot+j+1]) minRot = i-j-1;
            j = fail[j];
        }

        if(c != s[minRot+j+1]){
            if(c < s[minRot]) minRot = i;
            fail[i-minRot] = -1;
        }
        else{
            fail[i-minRot] = j+1;
        }
    }

    cout<<s.substr(minRot, n/2)<<"\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}
