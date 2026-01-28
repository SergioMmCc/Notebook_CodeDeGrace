#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        long long s, result;
        cin >> s;
        result = (s + 1)*(s + 1) - 1;
        cout << result << endl;
    }
    return 0;
}