#include <bits/stdc++.h>
using namespace std;

set<long long> getDivisors(long long n) {
    set<long long> divisors;
    for (long long i = 1; i * i <= n; ++i)
        if (n % i == 0)
            divisors.insert({i, n / i});
    return divisors;
}

bool isPractical (long long n) {
    set<long long> divisors = getDivisors(n);
    long long sum = 0;
    for (long long divisor : divisors) {
        if (divisor > sum + 1)
            return false;
        sum += divisor;
    }
    return true;
}

int main() {
    long long m;
    int t; cin >> t;
    while (t--) {
        cin >> m;
        cout << (isPractical(m) ? "Yes" : "No") << endl;
    }
}

/* Cabe resaltar que todos los multiplos de 6 son número prácticos, además
de que el único impar que es número práctico es el 1 */