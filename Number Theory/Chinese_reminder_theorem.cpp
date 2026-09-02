#include "../template.h"

/*
- Sirve para hallar x para un grupo de ecuaciones de la forma:
  x = a_1 % m_1
  x = a_2 % m_2
  ...
  x = a_n % m_n
- Una vez se halla una solucion se pueden crear infinitas de la forma
  x + m_1 * m_2 * ... * m_n
- Complejidad: O(n*log(n))
*/

vl a, b;

ll chinese_reminder(int len, ll B) {
    ll x = 0;
    // vl m(len), c(len);
    for0(i,len) {
        ll m = B/b[i];
        x += (a[i] * m * mod_inverse(m, b[i])) % B;
        // En caso de ser necesarios los vectores m[i] y c[i]
        // m[i] = B/b[i];
        // c[i] = m[i] * mod_inverse(m[i], b[i]);
        // x += (a[i] * c[i]) % B;
    }
    
    return x%B;
}

void solver(){
    int len; cin >> len;
    ll s1, s2;
    ll B = 1, x;
    for0(i,len){
        cin>>s1>>s2;
        a.pb(s1); b.pb(s2);
        B *= s2;
    }
    
    x = chinese_reminder(len, B);
    cout<<x<<endl;
}