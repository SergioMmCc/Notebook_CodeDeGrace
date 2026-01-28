#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool esTriangular (unsigned long long int n) {
    unsigned long long int k, triangular;
    k = (-1 + (unsigned long long int)sqrt(1 + 8 * (double)n)) / 2;
    triangular = k*(k+1)/2;
    if (n==triangular)
        return true;
    else
        return false;
}

int main() {
    unsigned long long int n, x=1, y=1, k, pastTriangular;
    while (scanf ("%llu", &n) && (n>0)) {
        k = (-1 + (unsigned long long int)sqrt(1 + 8 * (double)n)) / 2;
        if (n==1)
            x=y=1;
        else if (n==2) {
            x=1;
            y=2;
        }
        else {
            if ((esTriangular(n)) && (k%2==0)) {
                x=k;
                y=1;
            }
            else if ((esTriangular (n)) && (k%2==1)) {
                x=1;
                y=k;
            }
            else if (k%2==0) {
                pastTriangular = k*(k+1)/2;
                x= k+1 -(n-pastTriangular-1);
                y=1+n-pastTriangular-1;
            }
            else {
                pastTriangular = k*(k+1)/2;
                y= k+1 -(n-pastTriangular-1);
                x=1+n-pastTriangular-1;
            }
        }
        
        printf ("%llu %llu\n", x, y);
    }    
    return 0;
}
