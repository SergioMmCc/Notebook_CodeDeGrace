#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define myInfinite 2147483647

#define MAXT  200001

int binarySearch (int *A, int i, int j, int k) {
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

void myMerge (int *A, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    int *L, *R;
    L = (int *) malloc (sizeof (int) * (n1 +2));
    R = (int *) malloc (sizeof (int) * (n2 +2));
    
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

void MergeSort (int *A, int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}

int main() {
    long long int C, search, divide;
    int *arr, P;
    arr = (int *) malloc (sizeof (int) * MAXT);
    int M, comp;
    
    scanf("%lld", &C);
    scanf("%d", &M);
    
    for(int i = 1; i <= M; i++){
        scanf("%d", &P);
        arr[i] = P;
    }
    //array lleno 
    
    MergeSort(arr, 1, M);
    
    for(int i = 1; i <= M; i++){
    	divide = arr[i];
        if(C % divide == 0){
        	search = C/divide;
//        	printf ("%lld\n", search);
        	(int)search;
//        	printf ("%d\n", search);
            comp =  binarySearch(arr, 1, M, search);
            if(comp > 0){
                printf("%d %d\n", arr[i], arr[comp]);
                return 0;
            }
        }
    }
    return 0;
}
