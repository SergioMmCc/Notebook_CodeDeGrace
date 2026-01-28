#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define myInfinite 2147483647


struct num {
    int position, ascii;
};

void myMerge (struct num A[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    struct num L[n1+2], R[n2+2];
    for (i=1; i<=n1; i++) {
        L[i].ascii = A[p+i-1].ascii;
        L[i].position = A[p+i-1].position;
    }
    for (j=1; j<=n2; j++) {
        R[j].ascii = A[q+j].ascii;
        R[j].position = A[q+j].position;
    }
    L[n1+1].ascii = myInfinite;
    R[n2+1].ascii = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i].ascii <= R[j].ascii) {
            A[k].ascii = L[i].ascii;
            A[k].position = L[i].position;
            i++;
        }
        else {
            A[k].ascii = R[j].ascii;
            A[k].position = R[j].position;
            j++;
        }
    }
}

void MergeSort (struct num A[], int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
};

int main () {
	int N, ascii, lenght;
	struct num integerS[105];
	char s[105][1000];
	scanf ("%d", &N);
	for (int k = 1; k <= N; k++) {
	    ascii = 0;
	    scanf ("%s", s[k]);
	    lenght = strlen(s[k]);
	    for (int i = 0; i < lenght; i++) {
	        ascii += (int)(s[k][i]);
	    }
	    integerS[k].position = k;
	    integerS[k].ascii = ascii;
	}
	
	MergeSort (integerS, 1, N);
	
	for (int j = 1; j <= N; j++) {
	    printf ("%s\n", s[integerS[j].position]);
	}
	
	return 0;
}
