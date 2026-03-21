#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 100001
#define myInfiniteChar "zzzzzzzzzz"
#define myInfiniteInt 2147483647
#define MAXNAME 11

struct Street {
    char name [MAXNAME];
    int number;
};
struct Street streets [MAXT];

int binarySearch (struct Street streets [], int i, int j, char k []) {
    int m, comparar;

    if (i>j)
       return -1*i -1;
    else {
        m = (i+j) / 2;
        comparar = strcmp (streets[m].name, k);
        if (comparar == 0) 
            return m;
        else {
            if (comparar < 0)
                return binarySearch (streets, m+1, j, k);
            else
                return binarySearch (streets, i, m-1, k);
        }
    }
}

void myMerge (struct Street streets [], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k, comparar;
    struct Street L[n1+2], R[n2+2];
    for (i=1; i<=n1; i++)
        L[i] = streets[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = streets[q+j];
    strcpy(L[n1 + 1].name, myInfiniteChar);
    L [n1+1].number = myInfiniteInt;
    strcpy(R[n2 + 1].name, myInfiniteChar);
    R [n2+1].number = myInfiniteInt;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        comparar = strcmp (L[i].name, R[j].name);
        if (comparar <= 0) {
            streets[k] = L [i];
            i++;
        }
        else {
            streets[k] = R [j];
            j++;
        }
    }
}

void MergeSort (struct Street streets[], int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (streets, p, q);
        MergeSort (streets, q+1, r);
        myMerge (streets, p, q, r);
    }
}

int main() {
    int n, q, i, startingPosition, lastPosition, result;
    char startingStreet [MAXNAME], lastStreet [MAXNAME];
    scanf ("%d %d", &n, &q);
    for (i=1; i<=n; i++) {
        scanf ("%s", streets[i].name);
        streets[i].number = i;
    }
    MergeSort (streets, 1, n);
    for (i=1; i<=q; i++) {
        scanf ("%s %s", startingStreet, lastStreet);
        startingPosition = binarySearch (streets, 1, n, startingStreet);
        lastPosition = binarySearch (streets, 1, n, lastStreet);
        result = abs(streets[startingPosition].number - streets[lastPosition].number) -1;
        printf ("%d\n", result);
    }
    return 0;
}
