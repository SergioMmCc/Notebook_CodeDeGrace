// El angulo esta dado en radianes
// Probado para un problema con precisión de 10^-6

#include<bits/stdc++.h>
using namespace std;

const long double pi = 3.141592654;

/* Como calcular el seno de un ángulo utilizando
   la serie de Taylor */
long double ssin(long double x){ // Radianes
	int n = 20;
	long double sign = 1, factorial = 1, xp = x;
	long double ans = x;
	for(int i=1; i<=n; i++){
		sign *= -1;
		factorial *= (2*i) * (2*i + 1);
		xp *= x * x;
		ans += (sign * xp) / factorial;
	}
	return ans;
}

/* Como calcular el coseno de un ángulo utilizando
   la serie de Taylor */
long double ccos(long double x){ // Radianes
    int n = 20;
    long double sign = 1, factorial = 1, xp = 1;
    long double ans = 1;
    for(int i = 1; i <= n; i++){
        sign *= -1;
        factorial *= (2*i - 1) * (2*i);
        xp *= x * x;
        ans += (sign * xp) / factorial;
    }
    return ans;
}