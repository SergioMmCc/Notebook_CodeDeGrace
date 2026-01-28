#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 100001
#define MAXQ 10001

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

int main() {
    int n, q, i, w[MAXT], acumulados [MAXT], acumulado, k[MAXQ], result;
    while (scanf ("%d %d", &n, &q) != EOF) {
        for (i=1; i<=n; i++)
            scanf ("%d", &w[i]);
        
        acumulados [1] = 1;
        acumulado = 1;
        
        for (i=2; i<=n; i++) {
            acumulado += w[i];
            acumulados [i] = acumulado;
        }
        
        for (i=1; i<=q; i++)
            scanf ("%d", &k[i]);
        
        for (i=1; i<=q; i++) {
            result = binarySearch (acumulados, 1, n, k[i]);
            if (result < 0)
                result = -(result+2);
            
            if (i==1)
                printf ("%d", result);
            else 
                printf (" %d", result);
            
        }
        printf ("\n");
    }
    
    
    return 0;
}
