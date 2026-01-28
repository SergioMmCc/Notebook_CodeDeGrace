#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

int main () {
    long long int n , m;
    int d;

    scanf ("%lld %d", &n, &d);

    if (n%10 == d)
        m = n + 10;

    else if (n%10 < d)
        m = n - (n%10) + d;

    else
        m = n - (n%10) + d + 10;


    printf ("%lld\n", m);
    
    return 0;
}    
