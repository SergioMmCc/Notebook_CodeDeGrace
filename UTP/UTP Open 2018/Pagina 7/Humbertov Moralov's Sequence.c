#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, result;
    while (scanf ("%d", &n) && (n != 0)) {
        result = sqrt(n);
        if (result * result != n)result++;
        printf ("%d\n", result);
    }   
    return 0;
}
