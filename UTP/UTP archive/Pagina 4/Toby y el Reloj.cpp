#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 1;
    string hour, aux;
    cin >> hour;
    aux += hour[0];
    aux += hour[1];
    aux += hour[3];
    aux += hour[4];
    
    n = stoi(aux);
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << i << "\n";
    }
    
    return 0;
}
