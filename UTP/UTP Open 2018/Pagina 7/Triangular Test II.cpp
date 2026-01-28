#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 2;

int main() {
    vector <int> answer (maxn, 3);
    int n;
    
    for (int iIndex = 1, i = 2; iIndex < maxn; iIndex += i, i++) {
        for (int jIndex = 1, j = 2; jIndex < maxn; jIndex += j, j++) {
            if (jIndex + iIndex > maxn) break;
            answer.at(jIndex + iIndex) = 2;
        }
    }
    for (int iIndex = 1, i = 2; iIndex < maxn; iIndex += i, i++)
        answer.at(iIndex) = 1;
    
    while (cin >> n && n != EOF) cout << answer[n] << "\n";
    
    return 0;
}