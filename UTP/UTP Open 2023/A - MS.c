#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define infiniteChar "zzzzzzzzzzz"

typedef struct {
    char number [12];
    //int id;
} street;

void myMerge (street A[], int p, int q, int r) {
    int i, j, k, n1 = q - p + 1, n2 = r - q; 
    street L[n1 + 2], R[n2 + 2];

    for (i = 1; i <= n1; i++) {
        L[i] = A[p + i - 1];
	}

    for (j = 1; j <= n2; j++) {
        R[j] = A[q + j];
	}

    strcpy (L[n1 + 1].number, infiniteChar);
    strcpy (R[n2 + 1].number, infiniteChar);

    i = 1; 
    j = 1;

    for (k = p; k <= r; k++) {
        if (strcmp (L[i].number, R[j].number) <= 0) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort (street A[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort (A, p, q);
        mergeSort (A, q + 1, r);
        myMerge (A, p, q, r);
    }
}

int main () {
    street A[7];
    int index;
    char abc[12], acb[12], bac[12], bca[12], cab[12], cba[12], a[9], b[9], c[9];

    scanf ("%s %s %s", a, b, c);

    index = 1;
    strcat (abc, a);
    strcat (abc, b);
    strcat (abc, c);
    strcpy (A[index].number, abc);

    index = 2;
    strcpy (acb, a);
    strcat (acb, c);
    strcat (acb, b);
    strcpy (A[index].number, acb);

    index = 3;
    strcpy (bac, b);
    strcat (bac, a);
    strcat (bac, c);
    strcpy (A[index].number, bac);

    index = 4;
    strcpy (bca, b);
    strcat (bca, c);
    strcat (bca, a);
    strcpy (A[index].number, bca);

    index = 5;
    strcpy (cab, c);
    strcat (cab, a);
    strcat (cab, b);
    strcpy (A[index].number, cab);

    index = 6;
    strcpy (cba, c);
    strcat (cba, b);
    strcat (cba, a);
    strcpy (A[index].number, cba);

    mergeSort (A, 1, 6);

    printf ("%s\n", A[6].number);
}
