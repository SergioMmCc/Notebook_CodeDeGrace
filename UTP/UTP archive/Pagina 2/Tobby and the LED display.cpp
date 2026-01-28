#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;


int main() {
    long long n, t;
    char d;
    string u, m, b, aux;
    
    while (cin >> n >> t >> d) {
        t %= n;
        getline(cin, u);
        getline(cin, u);
        getline(cin, m);
        getline(cin, b);
        aux = m;

        if (d == 'R') {
            for (int i = 1; i < 2*n; i+=2) {
                if (i + 2*t > 2*n) 
                    aux[(2*t + i) - 2*n] = m[i];
                else   
                    aux[i + 2*t] = m[i];
            }
        }

        else {
            for (int i = 1; i < 2*n; i+=2) {
                if (i - 2*t < 1)
                    aux[i + 2*n - 2*t] = m[i];
                else
                    aux[i - 2*t] = m[i];
            }
        }
        cout << u << "\n" << aux << "\n" << b << "\n";
    }
    
    return 0;
}