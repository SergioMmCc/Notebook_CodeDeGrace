#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int binarySearch (int A [], int i, int j, int k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m] == k)
           return m;
        else if (k > A[m])
             i = m + 1;
           else
                j = m - 1;
    }
    return -i -1;
}

int main () {
    int *A, n, index, q, k, position;
    A = (int *) malloc (sizeof (int) * 100);
    
    while (scanf("%d", &n) != EOF) {
        for (index = 1; index<=n; index++)
            scanf ("%d", &A[index]);
              
        scanf ("%d", &q);
        for (index = 1; index <= q; index++) {
            scanf ("%d", &k);
            position = binarySearch (A, 1, n, k);
            if (position >= 0)
                printf ("\nThe element %d is in the position %d in the array. \n", k, position);
            else {
                printf ("\nThe element %d is not in the array.\n", k);
                printf ("The insertion point is: %d\n", -1*position -1);
            }
        }
    }
    return 0;
}
