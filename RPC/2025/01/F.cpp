#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    int ans = 0;
    int minn = 1001;
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            int save; cin>>save;
            ans += save;
            if((i + j) % 2) minn = min(minn, save);
        }
    }

    if(!(n % 2) && !(m % 2)) ans -= minn;
    cout<<ans<<endl;
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