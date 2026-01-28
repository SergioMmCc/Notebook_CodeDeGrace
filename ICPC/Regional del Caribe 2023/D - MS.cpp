#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define myInfinite 20

struct fight
{
    int atackOrDefense, position;
};


void myMerge (struct fight A[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    struct fight L[n1+2], R[n2+2];
    for (i=1; i<=n1; i++) {
        L[i].atackOrDefense = A[p+i-1].atackOrDefense;
        L[i].position = A[p+i-1].position;
    }
    for (j=1; j<=n2; j++) {
        R[j].atackOrDefense = A[q+j].atackOrDefense;
        R[j].position = A[q+j].position;
    }
    L[n1+1].atackOrDefense = myInfinite;
    R[n2+1].atackOrDefense = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i].atackOrDefense <= R[j].atackOrDefense) {
            A[k].atackOrDefense = L[i].atackOrDefense;
            A[k].position = L[i].position;
            i++;
        }
        else {
            A[k].atackOrDefense = R[j].atackOrDefense;
            A[k].position = R[j].position;
            j++;
        }
    }
}

void MergeSort (struct fight A[], int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
};

int main () {
    int i, assesment[4];
    struct fight k [5], d[5];
    
    for (i=1; i<= 3; i++) {
        scanf ("%d", &k[i].atackOrDefense);
        k[i].position = i;
    }
    for (i=1; i<= 3; i++) {
        scanf ("%d", &d[i].atackOrDefense);
        d[i].position = i;
    }
    
    MergeSort (k, 1, 3);
    MergeSort (d, 1, 3);
    
    if (k[2].atackOrDefense > d[1].atackOrDefense && k[3].atackOrDefense > d[2].atackOrDefense) {
        printf ("POSSIBLE\n");
        assesment[k[1].position] = d[3].position;
        assesment[k[2].position] = d[1].position;
        assesment[k[3].position] = d[2].position;
        printf ("%d %d %d\n", assesment[1], assesment[2], assesment[3]);
    }
    else
        printf ("IMPOSSIBLE\n");
    
    return 0;
}
