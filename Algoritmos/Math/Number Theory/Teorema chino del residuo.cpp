#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a, b;

ll mod_inverse(ll a, ll n) {
    ll i = n, v = 0, d = 1;
    while(a > 0) {
        ll t = i/a, x = a;
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


/*
  - Sirve para hallar una solucion a un grupo de ecuaciones de la forma:
    x = a_1 % m_1
    x = a_2 % m_2
    ...
    x = a_n % m_n
  - Una vez se halla una solucion se pueden crear infinitas de la forma
    x + m_1 * m_2 * ... * m_n
*/
// Complejidad: O(n*log(n))
ll chinese_reminder(int len, ll B) {
    ll x = 0;
    //vector<ll> m(len), c(len);
    for(int i = 0; i < len; i++) {
        ll m = B/b[i];
        x += (a[i] * m * mod_inverse(m, b[i])) % B;
        //En caso de ser necesarios los vectores m[i] y c[i]
        // m[i] = B/b[i];
        // c[i] = m[i] * mod_inverse(m[i], b[i]);
        // x += (a[i] * c[i]) % B;
    }
    
    return x%B;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int len; cin >> len;
    ll s1, s2;
    ll B = 1, x;
    for(int i = 0; i < len; i++) {
        cin >> s1 >> s2;
        a.push_back(s1); b.push_back(s2);
        B *= s2;
    }
    
    x = chinese_reminder(len, B);
    cout << x << endl;
    
    return 0;
}