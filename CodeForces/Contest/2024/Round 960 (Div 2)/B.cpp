#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n, x, y;
    cin >> n >> x >> y;
    int result[n+1];
    for(int i = 1; i <= n; i++)
        result[i] = 1;
        
    for(int i = x+1; i <= n; i+=2)
        result[i] *= -1;
    for(int i = y-1; i > 0; i -= 2)
        result[i] *= -1;
        
    for(int i = 1; i < n; i++)
        cout << result[i] << " ";
    cout << result[n] << "\n";
}

int main () {
    int t; cin >> t;
    while(t--) {
        solver();
    }
    return 0;
}