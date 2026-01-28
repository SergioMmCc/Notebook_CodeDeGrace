#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define myInfinite 2147483647
#define MAXT 1000000

int BinarySearch (int A [], int i, int j, int k) {
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

int main() {
    int length, A[MAXT + 1], pieces, l1, l2, search;
    bool result;
    
    while (scanf ("%d", &length) != EOF) {
        
        result = false;
        length *= 10000000;
        scanf ("%d", &pieces);
        for (int index = 1; index <= pieces; index++)
            scanf ("%d", &A[index]);
        
        MergeSort (A, 1, pieces);
        l1 = 1;
        l2 = pieces;
        while (l1 < l2 && !result) {
            search = length - A[l1];
            l2 = BinarySearch (A, l1 + 1, pieces, search);
            
            if (l2 > 0) {
                result = true;
                printf ("yes %d %d\n", A[l1], A[l2]);
            }
            else {
                l2 = -(l2 + 1);
                l1++;
            }
        }
        if (!result)
            printf ("danger\n");
    }
    
    return 0;
}
