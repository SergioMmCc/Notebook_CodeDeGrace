#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n;
    cin >> n;
    int freq[n+1];
    for(int i = 1; i <= n; i++)
        freq[i] = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    for(int i = 1; i <= n; i++) {
        if(freq[i] % 2 == 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main () {
    int t; cin >> t;
    while(t--) {
        solver();
    }
    return 0;
}