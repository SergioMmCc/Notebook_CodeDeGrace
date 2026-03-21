#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long n, pPosition, lPosition, pTime, lTime, hybridTime;
    cin >> n;
    while (n--) {
        cin >> pPosition >> lPosition >> pTime >> lTime;
        if (lPosition >= pPosition)
            cout << min({pTime * pPosition, lTime * lPosition}) << endl;
        else
            cout << min({pTime * pPosition, lTime * (pPosition * 2 - lPosition), pTime * (pPosition - lPosition) + lTime * lPosition}) << endl;
    }
}