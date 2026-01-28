#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n, mid, big;
    double result;
    
    while (cin >> n && n != 0) {
        mid = n/2;
        
        if (n % 2 == 0) 
            big = (4*mid*(mid+1)*(2*mid - 2)/3) + 2*mid;
        else
            big = 4*mid*(mid+1)*(2*mid + 1)/3;
        
        result = sqrt(((double)big/((double)n-1)));
        
        cout.precision(6);
        cout << fixed << result << "\n";
    }
}
