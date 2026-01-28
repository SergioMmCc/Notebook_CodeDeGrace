#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned long long int result, x, y;
    while (scanf ("%llu %llu", &x, &y) && (x != 0)) {
        result = (x + y - 1)*(x + y)/2;
        if ((x + y) % 2 == 0)
            result -= x - 1;
        else
            result -= y - 1;
        
        printf ("%llu\n", result);
    }
    return 0;
}
