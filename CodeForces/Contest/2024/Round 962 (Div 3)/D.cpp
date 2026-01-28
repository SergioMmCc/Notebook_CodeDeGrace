#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;

void solver() {
    vector<pii> possible;
    int n, x;cin>>n>>x;
    long long ans = 0;
    for(int a = 1; a <= n; a++) {
        int b = 1;
        while(b <= n/a) {
            possible.push_back({a, b});
            b++;
        }
    }
    for(pii test : possible) {
        int a = test.first, b = test.second;
        if(x-a-b <= 0)
            continue;
        ans += min((n - a*b)/(a+b), x-a-b);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}