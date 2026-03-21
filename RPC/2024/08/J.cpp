#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ld = long double;

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int x, y, n;
    cin>>x>>y>>n;
    int distance = 2e9 + 100;
    for(int i = 0; i < n; i++){
        int xi, yi;
        cin>>xi>>yi;
        distance = min(distance, abs(x - xi) + abs(y - yi));
    }

    ld result = distance + (ld)(n-1)/4.0;
    cout<<fixed<<setprecision(10)<<result<<endl;
    
    return 0;
}