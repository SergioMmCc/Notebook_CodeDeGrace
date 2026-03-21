#include <bits/stdc++.h>
using namespace std;
 
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a, b, c, n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        if ((a + b + c) % 9 == 0) {
            int nShots = (a + b + c) / 9;
            if (a >= nShots && b >= nShots && c >= nShots)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
}