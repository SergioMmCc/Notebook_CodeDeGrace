#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

void solver(){
    int k, n; cin>>k>>n;
    if(2*k <= n + 1 && 3*k >= n){
        string ans = "";
        while(n > 0){
            if(3*k == n){
                ans += "-X-";
                k--;
                n -= 3;
            }
            else if(!ans.size() || ans[ans.size() - 1] == '-'){
                ans += 'X';
                k--;
                n--;
            }
            else{
                ans += '-';
                n--;
            }
        }
        cout<<ans<<endl;
    }
    else cout<<'*'<<endl;
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