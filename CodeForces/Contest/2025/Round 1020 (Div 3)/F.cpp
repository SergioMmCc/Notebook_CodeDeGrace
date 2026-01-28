#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n; string s; cin>>n>>s;

    int up, down;
    if(s[0] == '0'){
        up = 0;
        down = n - 1;
    }
    else{
        up = 1;
        down = 0;
    }

    int ans = max(up, down);
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            if(s[i-1] == '1'){
                up = 1;
                down = 0;
            }
            else{ // s[i-1] == 0
                up = down + 1;
                down = 0;
            }
        }
        else{
            if(s[i-1] == '1'){
                up += i;
                down = n - i - 1;
            }
            else{
                up += i;
                down += n - i - 1;
            }
        }

        ans = max(ans, max(up, down));
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}