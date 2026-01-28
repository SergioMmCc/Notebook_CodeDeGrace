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

void swap (struct fight k[]) {
    for (int i = 4; i >= 2; i--) {
        k[i].position = k[i - 1].position;
        k[i].atackOrDefense = k[i - 1].atackOrDefense;
    }
    k[1].position = k[4].position;
    k[1].atackOrDefense = k[4].atackOrDefense;
}

int main () {
    int i, result, response, successfulFights, assesment[4], flag = 0;
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

    for (int j = 1; j <= 3; j++) {
        swap(k);
        
        successfulFights = 0;
        
        for (i = 1; i <= 3; i++) {
            response = k[i].atackOrDefense - d[i].atackOrDefense;
            if (response > 0) {
                successfulFights ++;
            }
        }
        if (successfulFights >= 2) {
            printf ("POSSIBLE\n");
            for (i = 1; i <= 3; i++)
                assesment[k[i].position] = i;
            printf ("%d ", assesment[1]);
            printf ("%d ", assesment[2]);
            printf ("%d\n", assesment[3]);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 4; i >= 3; i--) {
            k[i].position = k[i - 1].position;
            k[i].atackOrDefense = k[i - 1].atackOrDefense;
        }
        k[2].position = k[4].position;
        k[2].atackOrDefense = k[4].atackOrDefense;
    
        for (int j = 1; j <= 3; j++) {
            swap(k);
            
            successfulFights = 0;
            
            for (int i = 1; i <= 3; i++) {
                response = k[i].atackOrDefense - d[i].atackOrDefense;
                if (response > 0) {
                    successfulFights ++;
                }
            }
            if (successfulFights >= 2) {
                printf ("POSSIBLE\n");
                for (int i = 1; i <= 3; i++)
                    assesment[k[i].position] = i;
                printf ("%d ", assesment[1]);
                printf ("%d ", assesment[2]);
                printf ("%d\n", assesment[3]);
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        printf ("IMPOSSIBLE\n");
    
    return 0;
}
