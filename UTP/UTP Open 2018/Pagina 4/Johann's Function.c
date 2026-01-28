#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 1000000

unsigned long long int SergiosFunction (int n) {
    unsigned long long int result = 0;
    result = (unsigned long long int)n*(n+1)*(n+2)/6;
    return result;
}

int main() {
    int t, i, cases[MAXT];
    unsigned long long int result = 0;
    scanf ("%d", &t);
    for (i=1; i<=t; i++)
        scanf ("%d", &cases[i]);
    for (i=1; i<=t; i++) {
        result = SergiosFunction (cases[i]);
        printf ("%llu\n", result);
    }  
    return 0;
}

