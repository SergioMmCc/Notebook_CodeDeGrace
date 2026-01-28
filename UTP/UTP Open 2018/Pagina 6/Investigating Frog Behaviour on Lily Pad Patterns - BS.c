#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 1200001
#define MAXFROG 200001

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
    int n, i, x[MAXFROG], q, lilyPadsPosition=1, lookForFrog, lilyPads [MAXT], frogJumping, destiny, temp;
    scanf ("%d", &n);
    for (i=1; i<=n; i++)
        scanf ("%d", &x[i]);
    
    for (i=1; i<=MAXT; i++) {
        lookForFrog = binarySearch (x, 1, n, i);
        if (lookForFrog < 0) {
            lilyPads [lilyPadsPosition] = i;
            lilyPadsPosition++;
        }
    }
    
    scanf ("%d", &q);
    for (i=1; i<=q; i++) {
        frogJumping = 0;
        scanf ("%d", &frogJumping);
        destiny = binarySearch (lilyPads, 1, lilyPadsPosition - 1, x[frogJumping]);
        destiny = -(destiny+1);
        printf ("%d\n", lilyPads [destiny]);
        temp = x[frogJumping];
        x[frogJumping] = lilyPads [destiny];
        lilyPads [destiny] = temp;
        
    }
    return 0;
}
