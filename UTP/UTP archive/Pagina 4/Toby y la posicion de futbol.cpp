#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    long double x, y, xT = 0, yT = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        xT += x; yT += y;
    }
    xT /= n; yT /= n;
    cout << fixed << setprecision(3) << xT << " " << yT << "\n";
    
    return 0;
}