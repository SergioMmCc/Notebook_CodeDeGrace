#include <bits/stdc++.h>
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
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int ans = 2;
    if(x1 == 0 || x1 == 2024){
        if(y1 == 0 || y1 == 2024) ans--;
    }

    if(x2 == 0 || x2 == 2024){
        if(y2 == 0 || y2 == 2024) ans--;
    }

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