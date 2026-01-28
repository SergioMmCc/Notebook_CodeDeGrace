#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#define MAXT 2000100

int binarySearch (unsigned long long int *A, int i, int j, unsigned long long int k) {
    int m;
    if (i>j) 
        return -1*i - 1;
    else {
        m = (i+j)/2;
        if (k == A[m])
            return m;
        else if (k > A[m])
            return binarySearch (A, m+1, j, k);
        else 
            return binarySearch (A, i, m-1, k);
    }
}

int main () {
    unsigned long long int n, *save, parcial, index;
    int pos, primero = 0;
    
    save = (unsigned long long int *) malloc (sizeof (unsigned long long int) * MAXT);

    scanf ("%llu", &n);
    parcial = n;

    for (index = 2; index <= MAXT; index++) 
        save[index - 1] = (index * (index + 2) * (index + 1) / 6) - 1;

    while (parcial >= 3) {
        pos = binarySearch (save, 1, MAXT, parcial);

        if (pos < 0) {
            pos = pos*-1 - 2;
        }
        primero += pos;

        parcial -= save[pos];
    }

    printf ("%d %llu\n", primero, parcial);

    return 0;
}
