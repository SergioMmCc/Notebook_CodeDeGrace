#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXT 100000
#define myInfinite 2147483647

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
    int n, set [MAXT + 1], index, result;
    scanf ("%d", &n);
    for (index = 1; index <= n; index ++)
        scanf ("%d", &set [index]);
        
    MergeSort (set, 1, n);
    
    result = set [1] + set [2];
    
    printf ("%d\n", result);
    
    return 0;
}


