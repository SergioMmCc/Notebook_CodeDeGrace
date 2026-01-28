#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n, s; cin>>n>>s;
    int mini = 101, maxi = 0;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        mini = min(mini, save);
        maxi = max(maxi, save);
    }

    int ans;
    if(s <= mini) ans = abs(maxi - s);
    else if(s >= maxi) ans = abs(s - mini);
    else ans = min(s + maxi - 2*mini, 2*maxi - s - mini);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}