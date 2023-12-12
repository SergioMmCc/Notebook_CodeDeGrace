#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myInfinite 2147483647
#define MAXT 100

void myMerge (int A[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    int L[n1+2], R[n2+2];
    for (i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = A[q+j];
    L [n1+1] = myInfinite;
    R [n2+1] = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L [i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort (int A[], int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}


int main () {
    int A[MAXT+1], i, n;
    
    scanf ("%d", &n);
    for (i=1; i<=n; i++)
        scanf ("%d", &A[i]);
    
    for (i=1; i<=n; i++)
        printf ("%d ", A[i]);
    printf ("\n");
    
    MergeSort (A, 1, n);
    
    for (i=1; i<=n; i++)
        printf ("%d ", A[i]);
        printf ("\n");
    return 0;
}
