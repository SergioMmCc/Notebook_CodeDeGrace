#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q, answer; cin >> q;
    while (q--) {
        answer = 0;
        int n; cin >> n;
        answer += n/20;
        n -= 20 * (n/20);
        answer += n/10;
        n -= 10 * (n/10);
        answer += n/5;
        n -= 5 * (n/5);
        answer += n/2;
        n -= 2 * (n/2);
        answer += n;
        cout << answer << "\n";
    }
    return 0;
}
