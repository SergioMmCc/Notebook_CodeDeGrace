#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    vector<int> factorials(1,1);
    for (int i = 1; i <= 9; i++)
        factorials.push_back(factorials.back()*i);
    int serialNumber;
    cin >> serialNumber;
    string password;
    if (serialNumber == 1) {
        password = "0";
        serialNumber = 0;
    }
    while (serialNumber > 0) {
        auto nearestValue = upper_bound(factorials.begin(), factorials.end(), serialNumber) - 1;
        password = to_string(distance(factorials.begin(), nearestValue)) + password;
        serialNumber -= *nearestValue;
    }
    cout << password << endl;
}