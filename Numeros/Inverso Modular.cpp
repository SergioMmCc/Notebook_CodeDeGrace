#include <bits/stdc++.h>
using namespace std;

long long mod_inverse(long long a, long long n) {
    long long i = n, v = 0, d = 1;
    while(a > 0) {
        long long t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= n;
    if(v < 0)
        v += n;
    return v; // (a * v) mod n = 1
}

int main() {
    long long a, n;
    cin >> a >> n;
    cout << mod_inverse(a, n) << endl;
    return 0;
}