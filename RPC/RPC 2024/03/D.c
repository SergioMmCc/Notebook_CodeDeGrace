#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define int long long
#define limite 10005

long long power (long long base, int exponente) {
    long long num = 1;
	while (exponente--)
		num *= base;
	return num;
}

signed main() {
    bool es_primo[limite + 1];
    int counter = 2, flag = 0;
    long long num, exponent, root;
    scanf ("%lld", &num);
    
    es_primo[0] = es_primo[1] = false;
    for (int i = 2; i <= limite; ++i) 
        es_primo[i] = true;
    
    for (long long p = 2; p <= limite; p++) {
        if (es_primo[p]) {
            exponent = log (num) / log (p);
            if (power (p, exponent) == num && exponent % 2 != 0) {
                flag = 1;
                break;
            }
            for (long long i = p * p; i <= limite; i += p) 
                es_primo[i] = false;
        }
    }
    
    if (flag == 0) {
        root = sqrt(num);
        if (root * root == num)
            counter++;
        for (int i = 2; i <= root; i++) {
            if (num % i == 0)
                counter += 2;
            if (counter > 4)
                break;
        }
    }
    
    if (counter <= 4 && num != 1)
        flag = 1;
    
    printf ((flag == 0) ? "N\n" : "Y\n");
    
    return 0;
}
