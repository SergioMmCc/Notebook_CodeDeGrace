#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t, n, save, j;
    cin >> t;
    while (t--) {
        set<int> divisors;
        divisors.insert(1);
        cin >> n;
        cin >> save;
        for (j = 2; j * j < save; j++) {
            if (save % j == 0) {
                divisors.insert(j);
                divisors.insert(save/j);
            } 
        }
        if (j * j == save) 
            divisors.insert(j);
        divisors.insert(save);
        
        for (int i = 1; i < n && divisors.size() > 1; i++) {
            cin >> save;
            for (set<int>::iterator it = divisors.begin()++; it != divisors.end(); it++) {
                if (save % *it != 0) 
                    it = divisors.erase(it);
            }
        }
        set<int>::iterator it = --divisors.end();
        cout << *it << "\n";
    }
    
    return 0;
}