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
