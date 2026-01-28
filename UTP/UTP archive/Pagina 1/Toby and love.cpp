#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, ans;
    string s;
    cin >> n;
    while (n--) {
        ans = 0;
        cin >> s;
        if (s.size() > 3) {
            for (size_t i = 0; i < s.size() -3; i++) {
                if (s[i] == 'l' && s[i+1] == 'o' && s[i+2] == 'v' && s[i+3] == 'e')
                    ans++;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}