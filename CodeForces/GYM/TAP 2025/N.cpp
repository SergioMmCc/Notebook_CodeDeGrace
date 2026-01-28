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
    int n; cin>>n;
    int maxx = -1, minx = 1e8 + 1, maxy = -1, miny = 1e8 + 1;
    for(int i = 0; i < n; i++){
        int x, y; cin>>x>>y;
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
    }

    maxx++; minx--; maxy++; miny--;
    cout<<(2 * (maxx - minx) + 2 * (maxy - miny))<<endl;
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