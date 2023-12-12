#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int BinarySearch (int *A, int i, int j, int k) {
    int m;
    
    if (i>j)
       return -1*i -1;
    else {
         m = (i+j) / 2;
         if (A[m] == k) 
            return m;
            else {
                 if (k >A[m])
                    return BinarySearch (A, m+1, j, k);
                 else
                     return BinarySearch (A, i, m-1, k);
                 }
         }
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
            position = BinarySearch (A, 1, n, k);
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
