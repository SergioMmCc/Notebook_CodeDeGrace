#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAXT 2000000
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

int binarySearchFirstOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int binarySearchLastOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, result + 1, j, k);
        }
    }
    return result;
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
    int n, q, i, c[MAXT], tipo, k, a, b, buscar, nuevaPosicion, posicionSuperior, posicionInferior, r;
    scanf ("%d %d", &n, &q);
    for (i=1; i<=n; i++)
        scanf ("%d", &c[i]);
    MergeSort (c, 1, n);
    for (i=1; i<=q; i++) {
        scanf ("%d", &tipo);
        if (tipo == 1) {
            scanf (" %d", &k);
            buscar = binarySearch (c, 1, n, k);
            if (buscar < 0) {
                nuevaPosicion = -(buscar+1);
                c [nuevaPosicion] = k;
                if (c[n] < k)
                    n++;
            }
        }
        else if (tipo == 2) {
            scanf (" %d %d", &a, &b);
            posicionSuperior = binarySearchLastOccurrence (c, 1, n, b);
            posicionInferior = binarySearchFirstOccurrence (c, 1, n, a);
            if (posicionInferior < 0)
                posicionInferior = -(posicionInferior+1);
            if (posicionSuperior < 0)
                    posicionSuperior = -(posicionSuperior+2);
            r = posicionSuperior - posicionInferior + 1;
            printf ("%d\n", r);
        }
    }
    
    return 0;
}
