#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;cin >> q;
    int n, v;
    int result;
    int j;
    for (int i = 1; i <= q; i++) {
        result = 0;
        cin >> n >> v;
        v--;
        
        if (v == 0)
            cout << n << "\n";
        else {
            for (j = 1; j*j < v && j < n; j++) {
                if (v%j == 0) {
                    result++;
                    if(v/j <= n)
                        result++;
                }
            }
            if (j*j == v && j < n)
                result++;
            
            cout << result << "\n";
        }
    }

    return 0;
}
