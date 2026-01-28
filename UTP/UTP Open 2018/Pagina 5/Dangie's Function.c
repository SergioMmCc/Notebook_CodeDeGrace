#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int cases;
    unsigned long long int n, result;
    scanf ("%d", &cases);
    while (cases--) {
        scanf ("%llu", &n);
        result = ((n * n * n) - n) /3;
        printf ("%llu\n", result);
    }
    return 0;
}

