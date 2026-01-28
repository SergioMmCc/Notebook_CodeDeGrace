#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, save, q, l , r;
    while (cin >> n) {
        vector<int> w(100001), s(100001);
        w.push_back(0); s.push_back(0);
        
        for (int i = 1; i <= n; i++) {
            cin >> save;
            if (save == 1) {
                s[i] = s[i-1]+1;
                w[i] = w[i-1];
            }
            else {
                s[i] = s[i-1];
                w[i] = w[i-1]+1;
            }
        }
        cin >> q;
        while (q--) {
            cin >> l >> r;
            if (w[r] - w[l-1] > s[r] - s[l-1])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }  
    return 0;
}
