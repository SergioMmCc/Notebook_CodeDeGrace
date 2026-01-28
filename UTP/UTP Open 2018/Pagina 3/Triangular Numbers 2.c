#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long int n, triangular, k, kplus1;
    while (scanf ("%llu", &n) && (n>0)) {
        k = (-1 + (unsigned long long int)sqrt(1+8*(double)n)) / 2;
        kplus1 = k+1;
        if (k%2 == 0)
            k /= 2;
        else
            kplus1 /= 2;
        triangular = k*kplus1;
        if (triangular == n)
            printf ("YES\n");
        else
            printf ("NO\n");
    }  
    return 0;
}
