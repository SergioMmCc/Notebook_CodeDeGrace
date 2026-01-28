#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string binaryString;
    cin >> binaryString;
    int maxWidth = 0, currentWidth = 0;
    for (char c : binaryString) {
        if (c == '0')
            currentWidth++;
        else {
            if (currentWidth > maxWidth)
                maxWidth = currentWidth;
            currentWidth = 0;
        }
    }
    cout << ((maxWidth + 1) >> 1) << endl;
}