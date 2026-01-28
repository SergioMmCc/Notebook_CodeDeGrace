#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 1000001

int binarySearch (long long int A [], int i, int j, long long int k) {
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
    long long int numericCenter [MAXT], numberToLookFor, testCenter;
    int n, i, numberFlag = 0, j, lastNumberCenter = 2, flag [MAXT];
    
    numericCenter [1] = 1;
    flag [1] = 0;
    
    for (i=2; i<MAXT; i++) 
        numericCenter [i] = numericCenter [i-1] + i;
    
    for (i=2; i<MAXT; i++) {
        numberToLookFor = numericCenter [i] + numericCenter [i-1];
        testCenter = binarySearch (numericCenter, 1, MAXT - 1, numberToLookFor);
        
        if (testCenter > 0) {
            for (j=lastNumberCenter; j<testCenter; j++) 
                flag [j] = numberFlag;
            lastNumberCenter = testCenter;
            numberFlag ++;
        }
    }
    
    for (j=lastNumberCenter; j<MAXT; j++)
        flag [j] = numberFlag;
    
    while (scanf ("%d", &n) && (n>0))
        printf ("%d\n", flag [n]);
      
    return 0;
}
