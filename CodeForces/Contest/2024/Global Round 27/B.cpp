#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n; cin>>n;
    string ans;
    if(n % 2 == 0){
        for(int i = 1; i <= n - 2; i++)
            ans += '3';
        ans += "66";
    }
    else {
        if(n == 1 || n == 3)
            ans += "-1";
        else{
            for(int i = 1; i <= n - 4; i++)
                ans += '3';
            ans += "6366";
        }
    }

    cout<<ans<<endl;
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