#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 100000
#define myInfinite 2147483647

int binarySearch (int A [], int i, int j, int k) {
    int m;
    
    if (i>j)
       return -1*i -1;
    else {
         m = (i+j) / 2;
         if (A[m] == k) 
            return m;
            else {
                 if (k >A[m])
                    return binarySearch (A, m+1, j, k);
                 else
                     return binarySearch (A, i, m-1, k);
                 }
         }
}

int binarySearchLastOccurrence ( int A[] , int i, int j, int k) {
    int result , result2 ;
    result = binarySearch (A, i, j, k);
    if( result >= 0) {
        result2 = binarySearch (A, result + 1 , j, k) ;
        while ( result2 >= 0) {
            result = result2 ;
            result2 = binarySearch (A, result + 1 , j, k) ;
        }
    }
    return result ;
}

void myMerge (int A[], int p, int q, int r)
{
    int i, j, k, n1 = q - p + 1, n2 = r - q;
    int L [n1 + 2], R[n2 + 2];
    
    for (i = 1; i <= n1; i++)
    L[i] = A[p + i - 1];
    
    for (j = 1; j <= n2; j++)
    R[j] = A[q+j];
    
    L[n1+1] = myInfinite;
    R[n2+1] = myInfinite;
    i=1;
    j=1;
    
    for(k=p; k<=r; k++)
    {
    
    if (L[i] <= R[j])
    {
        A[k] = L [i];
        i++;
    }
    
    else 
    {
        A[k] = R [j];
        j++;
    }
    
  }
    
}

void MergeSort (int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        myMerge(A, p, q, r);
    }
}

int main() {
    int n, i, A [MAXT], q, consults [MAXT], result;
    while (scanf ("%d", &n) != EOF) {
        for (i=1; i<=n; i++) 
            scanf ("%d ", &A[i]);
        MergeSort(A, 1, n);
        scanf ("%d", &q);
        for (i=1; i<=q; i++) {
            result = 0;
            scanf ("%d ", &consults[i]);
            result = binarySearchLastOccurrence(A, 1, n, consults [i]);
            if (result < 0) 
                result = -1 * (result+2);
            printf ("%d ", result);
            
        }
        printf ("\n");
    }
       
    return 0;
}
