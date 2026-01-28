#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myInfinite 2147483647
#define MAXT 1005

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
    int n, q, A[MAXT], posicion;
    scanf ("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) 
        scanf ("%d", &A[i]);
        
    MergeSort(A, 1, n);
    posicion = binarySearch(A, 1, n, q);
    
    if (posicion < 0) 
        posicion = posicion * -1 -2;
    
    
    printf ("%d\n", A[posicion]);
    
    return 0;
}

