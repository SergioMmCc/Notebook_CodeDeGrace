#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n, result;cin>>n;
    result = n % 10;
    n /= 10;
    result += n;
    cout<<result<<endl;
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