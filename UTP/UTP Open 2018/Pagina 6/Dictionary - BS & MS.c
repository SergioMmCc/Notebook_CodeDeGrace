#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#define infiniteChar "zzzzzzzzzzzzzz"
#define MAXV 1000001

typedef struct {
    char number [15];
    //int id;
} street;

void myMerge (street A[], int p, int q, int r) {
    int i, j, k, n1 = q - p + 1, n2 = r - q; 
    street L[n1 + 2], R[n2 + 2];

    for (i = 1; i <= n1; i++) 
        L[i] = A[p + i - 1];

    for (j = 1; j <= n2; j++)
        R[j] = A[q + j];


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

int binarySearch (street A[], int i, int j, char k[]) {

    int m;
    if (i > j) {
        return -1*i - 1;
    }
    else {
        m = (i + j)/2;
        if (strcmp (A[m].number, k) == 0) {
            return m;
        }
        else {
            if (strcmp (A[m].number, k) < 0)
                return binarySearch (A, m + 1, j, k);
            else
                return binarySearch (A, i, m - 1, k);
        }
    }
}


int main () {
    int totalWords, totalCases, index, inicial, final, result;
    char save[15], inferior[15], superior[15];
    street A[MAXV];

    scanf ("%d %d", &totalWords, &totalCases);

    for (index = 1; index <= totalWords; index++) {
        scanf ("%s", save);
        strcpy (A[index].number, save);
    }

    mergeSort (A, 1, totalWords);

    while (totalCases--) {
        scanf ("%s %s", inferior, superior);
        inicial = binarySearch (A, 1, totalWords, inferior);
        final = binarySearch (A, 1, totalWords, superior);

        if (inicial < 0) 
            inicial = inicial*-1 - 1;
        
        if (final < 0) 
            final = final*-1 - 2;
        

        result = final - inicial + 1;
        printf ("%d\n", result);
    }
    return 0;
}
