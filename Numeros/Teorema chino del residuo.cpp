#include <bits/stdc++.h>
using namespace std;

vector<long long> a, b;

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
    return v;
}

long long chinese_reminder(int len, long long B) {
    long long x = 0;
    //vector<long long> m(len), c(len);
    for(int i = 0; i < len; i++) {
        long long m = B/b[i];
        x += (a[i] * m * mod_inverse(m, b[i])) % B;
        //En caso de ser necesarios los vectores m[i] y c[i]
        // m[i] = B/b[i];
        // c[i] = m[i] * mod_inverse(m[i], b[i]);
        // x += (a[i] * c[i]) % B;
    }
    
    return x%B;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL); //Entrada y salida rapida de C++

    int len; cin >> len;
    long long s1, s2;
    long long B = 1, x;
    for(int i = 0; i < len; i++) {
        cin >> s1 >> s2;
        a.push_back(s1); b.push_back(s2);
        B *= s2;
    }
    
    x = chinese_reminder(len, B);
    cout << x << endl;
    
    return 0;
}